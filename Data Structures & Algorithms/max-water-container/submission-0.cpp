class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int l = 0, r = n-1; 
        int maxAreas = 0; 
        while(l < r) {
            int minH = min(heights[l], heights[r]); 
            maxAreas = max(maxAreas, minH * (r-l)); 
            if(heights[l] < heights[r])
                l++; 
            else 
                r--; 
        }
        return maxAreas; 
    }
};
