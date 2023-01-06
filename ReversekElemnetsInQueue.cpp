// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.
// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

#include<bits/stdc++.h>
using namespace std;


queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st;
    int cnt=0;
    
    while(cnt<k){
        st.push(q.front());
        q.pop();
        
        cnt++;
    }
    
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    
   int n=q.size()-k;
    while(n--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

