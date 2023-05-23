#include<bits/stdc++.h>
class KthLargest {
public:
    vector<int> sol;
    int n;
    priority_queue<int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(int x:nums){
            pq.push(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        int cnt = 1;
        while(pq.size() > n) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */