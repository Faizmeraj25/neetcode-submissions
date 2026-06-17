class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; 
        int maxLen = 0; 
        int l = 0; 
        int n = s.size(); 
        for(int r = 0; r < n; r++) {
            if(mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]]+1, l); 
            }
            mp[s[r]] = r; 
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen; 
    }
};
