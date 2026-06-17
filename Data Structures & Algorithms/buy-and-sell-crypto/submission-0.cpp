class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int maxProf = 0; 
        // Find the max price in upcoming days for a particular price.
        vector<int> maxRightPrice(n); 
        maxRightPrice[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxRightPrice[i] = max(maxRightPrice[i+1], prices[i]); 
        }

        // Try to buy on each day and sell it on max Price day. 
        for(int i = 0;i < n; i++) {
            maxProf = max(maxProf, maxRightPrice[i] - prices[i]); 
        }
        return maxProf; 
    }
};
