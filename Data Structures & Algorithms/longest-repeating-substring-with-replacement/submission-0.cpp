class Solution {
public:

    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxLen = 0, maxFreq = 0; 
        unordered_map<char, int> mp; 
        for(int r = 0; r < n; r++) { 
            mp[s[r]]++; 
            maxFreq = max(maxFreq, mp[s[r]]); 
            while((r-l+1) - maxFreq > k) {
                mp[s[l]] --; 
                l++; 
            }
            maxLen = max(maxLen, r-l+1); 
        }
        return maxLen; 
    }
};
