class Solution {
public:
    bool isValid(unordered_map<char, int>& mp, string& s, string &t) {
        for(auto x: t) {
            if(mp[x] < 0)
                return false; 
        }
        return true; 
    }
    string minWindow(string s, string t) {
        string minString = ""; 
        int minLength = s.length()+1; 
        unordered_map<char, int> mp; 
        for(auto x: t) {
            mp[x] --; 
        }
        int l = 0; 
        for(int r = 0; r < s.length(); r++) {
            mp[s[r]] ++; 
            while(isValid(mp, s, t)) {
                if(minLength > (r-l+1)) {
                    minString = s.substr(l, r-l+1); 
                    minLength = r-l+1;
                }
                mp[s[l]] --; 
                l++; 
            }
        }
        return minString; 
    }
};
