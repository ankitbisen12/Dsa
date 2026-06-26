# Fact & Dimension Table — SQL Practice Questions

## Schema Used

```
dim_merchants
  merchant_id   (PK)
  cust_id
  category
  status
  event_ts

fact_transactions
  txn_id        (PK)
  merchant_id   (FK -> dim_merchants.merchant_id)
  txn_date      (FK -> dim_time.date)   -- assumed, needed for any time-based query
  amount

dim_time
  date          (PK)
  month
  year
```

> Note: `fact_transactions` originally had no date column, so a `txn_date` field
> (joining to `dim_time.date`) is assumed wherever a query needs to group by month/year.

---

## Q1. Total revenue and transaction count per merchant (all-time)

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount |
| dim_merchants | merchant_id, category |

**Description:** For each merchant, calculate the total revenue generated and the total number of transactions across the entire dataset, to see overall merchant scale.

**Solution:**
```sql
SELECT 
    f.merchant_id,
    m.category,
    SUM(f.amount) AS total_revenue,
    COUNT(*) AS total_transactions
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
GROUP BY f.merchant_id, m.category
ORDER BY total_revenue DESC;
```

---

## Q2. Distinct customer count per category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| dim_merchants | cust_id, category |

**Description:** Count the number of unique customers associated with each merchant category, to understand category-wise customer reach.

**Solution:**
```sql
SELECT 
    category,
    COUNT(DISTINCT cust_id) AS distinct_customers
FROM dim_merchants
GROUP BY category
ORDER BY distinct_customers DESC;
```

---

## Q3. Merchants with zero transactions

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| dim_merchants | merchant_id, category |
| fact_transactions | merchant_id |

**Description:** Identify merchants present in the dimension table that have never recorded a transaction in the fact table — useful for spotting inactive or dormant merchants.

**Solution:**
```sql
SELECT 
    m.merchant_id,
    m.category
FROM dim_merchants m
LEFT JOIN fact_transactions f ON m.merchant_id = f.merchant_id
WHERE f.merchant_id IS NULL;
```

---

## Q4. Quarterly revenue by category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount, txn_date |
| dim_merchants | merchant_id, category |
| dim_time | date, month, year |

**Description:** Roll up revenue by category at a quarterly grain (instead of monthly), useful for higher-level trend reporting.

**Solution:**
```sql
SELECT 
    t.year,
    CEIL(t.month / 3.0) AS quarter,
    m.category,
    SUM(f.amount) AS quarterly_revenue
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
JOIN dim_time t ON f.txn_date = t.date
GROUP BY t.year, CEIL(t.month / 3.0), m.category
ORDER BY t.year, quarter, m.category;
```

---

## Q5. Average revenue per active merchant, by category and month

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount, txn_date |
| dim_merchants | merchant_id, category |
| dim_time | date, month, year |

**Description:** For each category and month, compute revenue divided by the number of merchants that transacted — a normalized productivity metric per merchant.

**Solution:**
```sql
SELECT 
    t.year, t.month, m.category,
    SUM(f.amount) / COUNT(DISTINCT f.merchant_id) AS avg_revenue_per_merchant
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
JOIN dim_time t ON f.txn_date = t.date
GROUP BY t.year, t.month, m.category
ORDER BY t.year, t.month;
```

---

## Q6. Rank each merchant's revenue within its own category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount |
| dim_merchants | merchant_id, category |

**Description:** Within each category, rank merchants by their total revenue so the best and worst performers per category can be identified.

**Solution:**
```sql
WITH merchant_rev AS (
    SELECT 
        m.category, f.merchant_id,
        SUM(f.amount) AS revenue
    FROM fact_transactions f
    JOIN dim_merchants m ON f.merchant_id = m.merchant_id
    GROUP BY m.category, f.merchant_id
)
SELECT 
    category, merchant_id, revenue,
    DENSE_RANK() OVER (PARTITION BY category ORDER BY revenue DESC) AS rank_in_category
FROM merchant_rev
ORDER BY category, rank_in_category;
```

---

## Q7. First and last transaction date for each merchant

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, txn_date |

**Description:** Find the earliest and most recent transaction date per merchant — useful for merchant lifecycle / tenure analysis.

**Solution:**
```sql
SELECT 
    merchant_id,
    MIN(txn_date) AS first_txn_date,
    MAX(txn_date) AS last_txn_date
FROM fact_transactions
GROUP BY merchant_id;
```

---

## Q8. Customers who have transacted in more than one category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id |
| dim_merchants | merchant_id, cust_id, category |

**Description:** Identify customers whose transactions span multiple merchant categories, indicating cross-category purchasing behavior.

**Solution:**
```sql
SELECT 
    m.cust_id,
    COUNT(DISTINCT m.category) AS category_count
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
GROUP BY m.cust_id
HAVING COUNT(DISTINCT m.category) > 1;
```

---

## Q9. Merchants performing below their category's monthly average revenue

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount, txn_date |
| dim_merchants | merchant_id, category |
| dim_time | date, month, year |

**Description:** Flag merchants whose monthly revenue falls below the average revenue of their category that month — a simple underperformance check.

**Solution:**
```sql
WITH merchant_month_rev AS (
    SELECT 
        t.year, t.month, m.category, f.merchant_id,
        SUM(f.amount) AS merchant_revenue
    FROM fact_transactions f
    JOIN dim_merchants m ON f.merchant_id = m.merchant_id
    JOIN dim_time t ON f.txn_date = t.date
    GROUP BY t.year, t.month, m.category, f.merchant_id
),
cat_avg AS (
    SELECT 
        year, month, category,
        AVG(merchant_revenue) AS avg_category_revenue
    FROM merchant_month_rev
    GROUP BY year, month, category
)
SELECT 
    mr.year, mr.month, mr.category, mr.merchant_id, 
    mr.merchant_revenue, ca.avg_category_revenue
FROM merchant_month_rev mr
JOIN cat_avg ca 
    ON mr.year = ca.year AND mr.month = ca.month AND mr.category = ca.category
WHERE mr.merchant_revenue < ca.avg_category_revenue
ORDER BY mr.year, mr.month, mr.category;
```

---

## Q10. Day-of-week revenue trend

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | amount, txn_date |
| dim_time | date |

**Description:** Determine which day of the week generates the highest total revenue, useful for staffing/marketing timing decisions.

**Solution:**
```sql
SELECT 
    TO_CHAR(t.date, 'Day') AS day_of_week,
    SUM(f.amount) AS total_revenue
FROM fact_transactions f
JOIN dim_time t ON f.txn_date = t.date
GROUP BY TO_CHAR(t.date, 'Day')
ORDER BY total_revenue DESC;
```

---

## Q11. Highest single-day revenue overall

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | amount, txn_date |

**Description:** Find the single calendar day with the highest total transaction revenue across all merchants and categories.

**Solution:**
```sql
SELECT 
    txn_date,
    SUM(amount) AS daily_revenue
FROM fact_transactions
GROUP BY txn_date
ORDER BY daily_revenue DESC
LIMIT 1;
```

---

## Q12. Weekday vs. weekend revenue split, per category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount, txn_date |
| dim_merchants | merchant_id, category |
| dim_time | date |

**Description:** Compare how much revenue each category generates on weekdays vs. weekends, to spot categories with strong weekend skew (e.g. entertainment, dining).

**Solution:**
```sql
SELECT 
    m.category,
    CASE 
        WHEN EXTRACT(DOW FROM t.date) IN (0,6) THEN 'Weekend'
        ELSE 'Weekday'
    END AS day_type,
    SUM(f.amount) AS revenue
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
JOIN dim_time t ON f.txn_date = t.date
GROUP BY m.category, day_type
ORDER BY m.category, day_type;
```

---

## Q13. Median transaction amount per category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount |
| dim_merchants | merchant_id, category |

**Description:** Calculate the median (not average) transaction value per category — more robust to outliers than a simple average.

**Solution:**
```sql
SELECT 
    m.category,
    PERCENTILE_CONT(0.5) WITHIN GROUP (ORDER BY f.amount) AS median_txn_amount
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
GROUP BY m.category;
```

---

## Q14. Top 3 categories by revenue in the latest available year

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount, txn_date |
| dim_merchants | merchant_id, category |
| dim_time | date, year |

**Description:** Identify the three best-performing categories by total revenue, restricted to the most recent year present in the data.

**Solution:**
```sql
WITH yearly_cat_rev AS (
    SELECT 
        t.year, m.category,
        SUM(f.amount) AS revenue
    FROM fact_transactions f
    JOIN dim_merchants m ON f.merchant_id = m.merchant_id
    JOIN dim_time t ON f.txn_date = t.date
    GROUP BY t.year, m.category
),
latest_year AS (
    SELECT MAX(year) AS yr FROM yearly_cat_rev
)
SELECT 
    yc.year, yc.category, yc.revenue
FROM yearly_cat_rev yc
JOIN latest_year ly ON yc.year = ly.yr
ORDER BY yc.revenue DESC
LIMIT 3;
```

---

## Q15. Transaction amount distribution by bucket, per category

**Tables & Fields Used**

| Table | Fields Used |
|---|---|
| fact_transactions | merchant_id, amount |
| dim_merchants | merchant_id, category |

**Description:** Bucket transactions into Low / Medium / High amount ranges per category, to understand the typical transaction-size mix within each category.

**Solution:**
```sql
SELECT 
    m.category,
    CASE 
        WHEN f.amount < 100 THEN 'Low (<100)'
        WHEN f.amount BETWEEN 100 AND 500 THEN 'Medium (100-500)'
        ELSE 'High (>500)'
    END AS amount_bucket,
    COUNT(*) AS txn_count,
    SUM(f.amount) AS bucket_revenue
FROM fact_transactions f
JOIN dim_merchants m ON f.merchant_id = m.merchant_id
GROUP BY m.category, amount_bucket
ORDER BY m.category, amount_bucket;
```
