# 50 Python Coding Questions for Data Engineer Interviews

Organized by category. Each question includes a description and sample test cases (input → output).

---

## Section 1: Dictionaries

### Q1. Merge Two Dictionaries (Sum on Conflict)
**Description:** Merge `d2` into `d1`. If a key exists in both, add the values. If not, insert the new key-value pair.

**Test Cases:**
- Input: `d1={"a":100,"b":200,"c":300}`, `d2={"b":300,"d":600}`
- Output: `{"a":100,"b":500,"c":300,"d":600}`

---

### Q2. Merge Dictionaries — Keep Maximum Value
**Description:** Merge two dictionaries. On key conflict, keep the larger value instead of summing.

**Test Cases:**
- Input: `d1={"a":100,"b":200,"c":300}`, `d2={"b":150,"d":600}`
- Output: `{"a":100,"b":200,"c":300,"d":600}`

---

### Q3. Word Frequency Counter
**Description:** Given a sentence, count how many times each word appears.

**Test Cases:**
- Input: `"data engineers build data pipelines and data lakes"`
- Output: `{"data":3,"engineers":1,"build":1,"pipelines":1,"and":1,"lakes":1}`

---

### Q4. Group Records by a Field
**Description:** Given a list of dictionaries (rows), group the `"name"` values by `"dept"`.

**Test Cases:**
- Input: `[{"dept":"sales","name":"Amit"},{"dept":"tech","name":"Riya"},{"dept":"sales","name":"Karan"}]`
- Output: `{"sales":["Amit","Karan"],"tech":["Riya"]}`

---

### Q5. Flatten a Nested Dictionary
**Description:** Flatten a nested dictionary into a single-level dictionary with dot-separated keys.

**Test Cases:**
- Input: `{"a":1,"b":{"c":2,"d":{"e":3}}}`
- Output: `{"a":1,"b.c":2,"b.d.e":3}`

---

### Q6. Unflatten a Dictionary
**Description:** Reverse of Q5 — convert a dot-separated flat dictionary back into a nested dictionary.

**Test Cases:**
- Input: `{"a":1,"b.c":2,"b.d.e":3}`
- Output: `{"a":1,"b":{"c":2,"d":{"e":3}}}`

---

### Q7. Find Common and Unique Keys Between Two Dictionaries
**Description:** Print keys common to both dictionaries, and keys unique to each.

**Test Cases:**
- Input: `d1={"a":1,"b":2,"c":3}`, `d2={"b":20,"c":30,"d":40}`
- Output: `Common: ['b', 'c']`, `Unique to d1: ['a']`, `Unique to d2: ['d']`

---

### Q8. Invert a Dictionary (Keys ↔ Values)
**Description:** Swap keys and values. If duplicate values exist, group the original keys into a list.

**Test Cases:**
- Input: `{"a":1,"b":2,"c":1}`
- Output: `{1:["a","c"],2:["b"]}`

---

### Q9. Sort a Dictionary by Value
**Description:** Return a dictionary sorted by value in descending order.

**Test Cases:**
- Input: `{"a":50,"b":90,"c":10}`
- Output: `{"b":90,"a":50,"c":10}`

---

### Q10. Convert List of Tuples to Dictionary (Group Values)
**Description:** Convert a list of key-value tuples into a dictionary, grouping values when keys repeat.

**Test Cases:**
- Input: `[("a",1),("b",2),("a",3),("c",4),("b",5)]`
- Output: `{"a":[1,3],"b":[2,5],"c":[4]}`

---

## Section 2: Lists & Arrays

### Q11. Remove Duplicates (Preserve Order)
**Description:** Remove duplicate elements from a list while preserving the original order of first occurrence.

**Test Cases:**
- Input: `[1,2,2,3,4,4,5,5,5]`
- Output: `[1,2,3,4,5]`

---

### Q12. Chunk a List into Batches
**Description:** Split a list into sublists (batches) of a given size. Useful for simulating batch processing.

**Test Cases:**
- Input: `data=[1,2,3,4,5,6,7,8,9,10]`, `batch_size=3`
- Output: `[[1,2,3],[4,5,6],[7,8,9],[10]]`

---

### Q13. Flatten a Nested List
**Description:** Flatten an arbitrarily nested list into a single flat list.

**Test Cases:**
- Input: `[1,[2,3,[4,5]],6,[7,[8,[9]]]]`
- Output: `[1,2,3,4,5,6,7,8,9]`

---

### Q14. Find the Second Largest Distinct Value
**Description:** Find the second largest distinct number in a list without using `sorted()` or `max()`.

**Test Cases:**
- Input: `[10,5,8,20,20,3]`
- Output: `10`

---

### Q15. Top N Most Frequent Elements
**Description:** Return the N most frequently occurring elements in a list, ordered by frequency.

**Test Cases:**
- Input: `l1=[1,2,2,3,4,4,4,5,5,5,5]`, `n=2`
- Output: `[5,4]`

---

### Q16. Find Missing Numbers in a Range
**Description:** Given a list of integers and a range, find which numbers in the range are missing from the list.

**Test Cases:**
- Input: `nums=[1,2,4,6,7]`, `range=1..7`
- Output: `[3,5]`

---

### Q17. Rotate a List
**Description:** Rotate a list to the right by `k` positions.

**Test Cases:**
- Input: `[1,2,3,4,5]`, `k=2`
- Output: `[4,5,1,2,3]`

---

### Q18. Intersection and Union of Two Lists
**Description:** Find the intersection and union of two lists without using set operators directly (implement the logic).

**Test Cases:**
- Input: `l1=[1,2,3,4]`, `l2=[3,4,5,6]`
- Output: `Intersection: [3,4]`, `Union: [1,2,3,4,5,6]`

---

### Q19. Move All Zeros to the End
**Description:** Move all zeros in a list to the end while keeping the relative order of non-zero elements.

**Test Cases:**
- Input: `[0,1,0,3,12]`
- Output: `[1,3,12,0,0]`

---

### Q20. Find Pairs That Sum to a Target (Two Sum)
**Description:** Given a list of numbers and a target sum, find all unique pairs of numbers that add up to the target.

**Test Cases:**
- Input: `nums=[2,7,11,15,1,9]`, `target=9`
- Output: `[(2,7)]`

---

## Section 3: Strings

### Q21. Check if Two Strings Are Anagrams
**Description:** Check whether two strings are anagrams of each other (ignore case and spaces).

**Test Cases:**
- Input: `"listen"`, `"silent"`
- Output: `True`

---

### Q22. Find the First Non-Repeating Character
**Description:** Find the first character in a string that does not repeat.

**Test Cases:**
- Input: `"swiss"`
- Output: `"w"`

---

### Q23. Reverse Words in a Sentence
**Description:** Reverse the order of words in a sentence without reversing the letters of each word.

**Test Cases:**
- Input: `"data engineering is fun"`
- Output: `"fun is engineering data"`

---

### Q24. Check if a String is a Palindrome
**Description:** Check if a given string reads the same forwards and backwards (ignore case/spaces/punctuation).

**Test Cases:**
- Input: `"A man a plan a canal Panama"`
- Output: `True`

---

### Q25. Parse a CSV-style String into a Dictionary
**Description:** Given a header row and a data row as comma-separated strings, convert them into a dictionary.

**Test Cases:**
- Input: `header="id,name,dept"`, `row="1,Amit,sales"`
- Output: `{"id":"1","name":"Amit","dept":"sales"}`

---

### Q26. Count Vowels and Consonants
**Description:** Count the number of vowels and consonants in a given string.

**Test Cases:**
- Input: `"DataEngineer"`
- Output: `Vowels: 5, Consonants: 7`

---

### Q27. Mask Sensitive Data (e.g., Emails or Card Numbers)
**Description:** Given an email string, mask part of it for display, e.g. keep first 2 characters and domain, mask the rest.

**Test Cases:**
- Input: `"amit.kumar@gmail.com"`
- Output: `"am*******@gmail.com"`

---

### Q28. Find Longest Word in a Sentence
**Description:** Return the longest word in a given sentence. If there's a tie, return the first one.

**Test Cases:**
- Input: `"the quick brown fox jumps"`
- Output: `"quick"`

---

## Section 4: Data Aggregation / ETL-Style Problems

### Q29. Deduplicate Records by Key (List of Dicts)
**Description:** Given a list of dictionaries representing rows, remove duplicates based on a specific key (e.g., `"id"`), keeping the first occurrence and preserving order.

**Test Cases:**
- Input: `[{"id":1,"name":"A"},{"id":2,"name":"B"},{"id":1,"name":"A_dup"}]`
- Output: `[{"id":1,"name":"A"},{"id":2,"name":"B"}]`

---

### Q30. Detect Duplicate Rows in Tabular Data
**Description:** Given a list of lists (representing table rows), remove exact duplicate rows while preserving order.

**Test Cases:**
- Input: `[[1,"Amit","sales"],[2,"Riya","tech"],[1,"Amit","sales"]]`
- Output: `[[1,"Amit","sales"],[2,"Riya","tech"]]`

---

### Q31. Aggregate Sales Data by Category
**Description:** Given a list of transaction dictionaries, compute total sales amount grouped by category.

**Test Cases:**
- Input: `[{"category":"A","amount":100},{"category":"B","amount":200},{"category":"A","amount":50}]`
- Output: `{"A":150,"B":200}`

---

### Q32. Find Null/Missing Values in Records
**Description:** Given a list of dictionaries (rows), identify which rows have missing or `None` values in any field.

**Test Cases:**
- Input: `[{"id":1,"name":"A"},{"id":2,"name":None},{"id":3,"name":"C"}]`
- Output: `[{"id":2,"name":None}]`

---

### Q33. Join Two Datasets on a Key (Like SQL INNER JOIN)
**Description:** Given two lists of dictionaries, join them on a common key (similar to an SQL inner join).

**Test Cases:**
- Input: `customers=[{"id":1,"name":"Amit"},{"id":2,"name":"Riya"}]`, `orders=[{"cust_id":1,"item":"Laptop"},{"cust_id":2,"item":"Phone"}]`
- Output: `[{"id":1,"name":"Amit","item":"Laptop"},{"id":2,"name":"Riya","item":"Phone"}]`

---

### Q34. Pivot a List of Records into a Wide Format
**Description:** Convert row-based records into a pivoted dictionary keyed by an identifier, with other fields as nested values.

**Test Cases:**
- Input: `[{"date":"2024-01","metric":"sales","value":100},{"date":"2024-01","metric":"cost","value":40}]`
- Output: `{"2024-01":{"sales":100,"cost":40}}`

---

### Q35. Compute a Running Total (Cumulative Sum)
**Description:** Given a list of numbers, compute the running/cumulative total at each index.

**Test Cases:**
- Input: `[10,20,30,40]`
- Output: `[10,30,60,100]`

---

### Q36. Detect Outliers Using Simple Threshold (IQR-free)
**Description:** Given a list of numbers, flag values that are more than 2x the average as outliers.

**Test Cases:**
- Input: `[10,12,11,13,100,9]`
- Output: `Outliers: [100]`

---

### Q37. Validate Schema of Records
**Description:** Given an expected set of keys and a list of record dictionaries, identify records that are missing any expected key.

**Test Cases:**
- Input: `expected_keys={"id","name","dept"}`, `records=[{"id":1,"name":"A","dept":"sales"},{"id":2,"name":"B"}]`
- Output: `Invalid records: [{"id":2,"name":"B"}]`

---

### Q38. Convert List of Records to CSV String (No Library)
**Description:** Convert a list of dictionaries into a CSV-formatted string manually (header + rows), without using the `csv` module.

**Test Cases:**
- Input: `[{"id":1,"name":"Amit"},{"id":2,"name":"Riya"}]`
- Output: `"id,name\n1,Amit\n2,Riya"`

---

## Section 5: Sets & Tuples

### Q39. Find Symmetric Difference Between Two Sets
**Description:** Find elements that are in either of two sets, but not in both.

**Test Cases:**
- Input: `{1,2,3,4}`, `{3,4,5,6}`
- Output: `{1,2,5,6}`

---

### Q40. Check if One List is a Subset of Another
**Description:** Check whether all elements of `list_a` exist in `list_b`.

**Test Cases:**
- Input: `list_a=[1,2,3]`, `list_b=[1,2,3,4,5]`
- Output: `True`

---

### Q41. Find Duplicate Elements Across Multiple Lists
**Description:** Given multiple lists, find elements that appear in more than one list.

**Test Cases:**
- Input: `l1=[1,2,3]`, `l2=[3,4,5]`, `l3=[5,6,7]`
- Output: `{3,5}`

---

### Q42. Count Unique Elements Without Using `set()`
**Description:** Count the number of unique elements in a list manually (without the built-in `set` type).

**Test Cases:**
- Input: `[1,2,2,3,3,3,4]`
- Output: `4`

---

## Section 6: Sorting & Searching

### Q43. Implement Binary Search
**Description:** Implement binary search to find the index of a target value in a sorted list.

**Test Cases:**
- Input: `nums=[1,3,5,7,9,11]`, `target=7`
- Output: `3`

---

### Q44. Sort a List of Dictionaries by Multiple Keys
**Description:** Sort a list of dictionaries first by `"dept"` (ascending), then by `"salary"` (descending).

**Test Cases:**
- Input: `[{"name":"A","dept":"tech","salary":50},{"name":"B","dept":"tech","salary":80},{"name":"C","dept":"sales","salary":60}]`
- Output: `[{"name":"C","dept":"sales","salary":60},{"name":"B","dept":"tech","salary":80},{"name":"A","dept":"tech","salary":50}]`

---

### Q45. Implement Merge Sort
**Description:** Implement the merge sort algorithm to sort a list of integers.

**Test Cases:**
- Input: `[5,2,9,1,5,6]`
- Output: `[1,2,5,5,6,9]`

---

### Q46. Find Kth Smallest Element
**Description:** Find the Kth smallest element in an unsorted list without fully sorting it (e.g., using a heap or partition logic).

**Test Cases:**
- Input: `nums=[7,10,4,3,20,15]`, `k=3`
- Output: `7`

---

## Section 7: Miscellaneous / Algorithmic

### Q47. Generate Fibonacci Sequence Using a Generator
**Description:** Write a generator function that yields the Fibonacci sequence up to `n` terms (memory-efficient, useful for streaming-style processing).

**Test Cases:**
- Input: `n=7`
- Output: `[0,1,1,2,3,5,8]`

---

### Q48. Find Longest Consecutive Sequence of Dates
**Description:** Given a list of dates (as strings, unsorted), find the longest run of consecutive calendar days.

**Test Cases:**
- Input: `["2024-01-01","2024-01-02","2024-01-04","2024-01-05","2024-01-06"]`
- Output: `["2024-01-04","2024-01-05","2024-01-06"]`

---

### Q49. Sliding Window Maximum
**Description:** Given a list of numbers and a window size `k`, find the maximum value in each sliding window.

**Test Cases:**
- Input: `nums=[1,3,-1,-3,5,3,6,7]`, `k=3`
- Output: `[3,3,5,5,6,7]`

---

### Q50. Memory-Efficient Large File Line Counter (Simulated)
**Description:** Given a large list of strings representing lines of a file, count how many lines contain a specific keyword — write it in a way that would work efficiently if reading from a file line-by-line (using a generator pattern instead of loading everything into memory at once).

**Test Cases:**
- Input: `lines=["error: disk full","info: ok","error: timeout","info: ok"]`, `keyword="error"`
- Output: `2`

---

## How to Use This List
1. Try solving each problem on your own first — without `sorted()`, `Counter`, or other shortcuts, if the question says "without using X."
2. Time yourself: aim for 5–10 minutes per easy/medium question.
3. After solving, think about **time and space complexity** — interviewers often ask this as a follow-up.
4. For ETL-style questions (Section 4), think about how the same logic would scale if the data didn't fit in memory (e.g., using generators, chunked processing, or a database/Spark equivalent).
