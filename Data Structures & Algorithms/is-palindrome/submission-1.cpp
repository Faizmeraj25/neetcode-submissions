class Solution {
public:
    bool isCap(char c) {
        return c >= 'A' && c <= 'Z'; 
    }
    bool isNum(char s) {
        return s >= '0' && s <= '9'; 
    }
    bool check(char a, char b){
        if(isNum(a) && isNum(b))
        {
            return a == b; 
        } 
        else if(!isNum(a) && !isNum(b)) 
        {
            if((isCap(a) && isCap(b)) || (!isCap(a) && !isCap(b)))
            return  a == b; 
            else if(!isCap(a) && isCap(b))
                return (a-32) == b; 
            else if(isCap(a) && !isCap(b))
                return a == (b-32); 
        } else 
        {
            return false; 
        }


    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); 
    }
    bool isPalindrome(string s) {
        int n = s.length(); 
        int start = 0, end = n-1;
        while(start <= end) {
            if(!alphaNum(s[start])) {
                start++; 
                continue; 
            }
            if(!alphaNum(s[end])) {
                    end--; 
                    continue; 
            }
            if(!check(s[start], s[end]))
                return false; 
            else 
            {
                start ++; 
                end--; 
            }
        }
        return true; 
    }
};
