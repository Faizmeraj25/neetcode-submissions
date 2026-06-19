class Solution {
public:
    int getMatchCount(vector<int>& count1, vector<int>& count2) {
       int match = 0; 
        for(int i = 0;i < count1.size(); i++) {
            match += (count1[i] == count2[i]); 
        }
        return match; 
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0); 
        vector<int> count2(26, 0);
        int n1 = s1.length(), n2 = s2.length(), l = 0; 
        if(n1 > n2) return false; 
        for(int i = 0;i < n1; i++) {
            count1[s1[i]-'a'] ++;
            count2[s2[i]-'a']++; 

        }
        int match = getMatchCount(count1, count2); 
        
        for(int r = n1 ; r < n2; r++) {
            if(match == 26) return true; 
            count2[s2[l]-'a']--;
            if(count2[s2[l]-'a'] == count1[s2[l]-'a'])
              match++; 
            else if(count2[s2[l]-'a']+1 == count1[s2[l]-'a'])
                match--; 
            count2[s2[r]-'a']++; 
            if(count2[s2[r]-'a'] == count1[s2[r]-'a'])
                 match++; 
            else if(count2[s2[r]-'a']-1 == count1[s2[r]-'a'])
                match--; 
            l++;  
          
        }
        return match == 26; 
    }
};
