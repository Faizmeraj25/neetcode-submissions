class Solution {
public:
    bool checkForMatch(vector<int> &count1, vector<int>& count2) {
        int c = 0; 
        for(int i = 0; i < count1.size(); i++) {
            c += (count1[i] == count2[i]); 
        }
        return c == 26; 
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0); 
        vector<int> count2(26, 0); 
        int n1 = s1.length(), n2 = s2.length(), l = 0; 
        if(n1 > n2) return false; 
        for(int i = 0;i < n1; i++) {
            count1[s1[i]-'a'] ++; 
        }
        for(int i = 0;i < n1; i++) {
            count2[s2[i]-'a']++; 
        }
        if(checkForMatch(count1, count2)) return true; 
        for(int r = n1 ; r < n2; r++) {
            count2[s2[r]-'a']++; 
            count2[s2[l]-'a']--;
            l++;  
            if(checkForMatch(count1, count2)) return true; 
        }
        return false; 
    }
};
