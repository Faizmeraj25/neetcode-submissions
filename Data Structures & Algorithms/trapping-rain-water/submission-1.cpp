class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        // 1. Compute the left an right greater heights.
        vector<int> leftH(n), rightH(n); 
        int maxlH = 0, maxrH = 0;  
        for(int i = 0;i < n; i++) {
            leftH[i] = maxlH; 
            maxlH = max(maxlH, height[i]); 
        }
        for(int i = n-1; i >= 0; i--) {
            rightH[i] = maxrH; 
            maxrH = max(maxrH, height[i]); 
        }

        // 2. Compute the total water trapped. 
        int totalWaterTrapped = 0; 
        for(int i = 0; i < n; i++) {
            int waterAtCurrentIndex = max(0, min(leftH[i], rightH[i]) - height[i]); 
            totalWaterTrapped += waterAtCurrentIndex; 
        }
        return totalWaterTrapped; 
    }
};
