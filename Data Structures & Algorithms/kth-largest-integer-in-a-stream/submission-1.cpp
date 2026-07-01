class KthLargest {
    private:
     void checkAndAdd(int val) {
        if(pq.size() < K) {
            pq.push(val); 
            return; 
        }
        if(pq.top() < val) {
            pq.pop(); 
            pq.push(val); 
        }
    }
public:
    int K; 
    vector<int> result; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    KthLargest(int k, vector<int>& nums) {  
        K = k;       
        for(auto &x: nums) {
            checkAndAdd(x); 
        }
        
    }
    
    int add(int val) {
        checkAndAdd(val); 
        return pq.top(); 
    }
};
