class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; 
        int maxLen = 0; 
        int l = 0; 
        int n = s.size(); 
        for(int r = 0; r < n; r++) {
            mp[s[r]]++; 
            while(l <= r && mp[s[r]] > 1) {
                mp[s[l]]--; 
                l++; 
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen; 
    }
};
