class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        char prev = s[len-1];
        int ans = 0;
        bool found;
        
        for(int i=len-2; i>=0; i--){
            found = false;
            if (s[i] == 'I' && prev == 'V') {
                ans += 4;
                prev = '-';
                found = true;
                
            } 
            else if (s[i] == 'I' && prev == 'X') {
                ans += 9;
                prev = '-';
                found = true;
                
            }
            else if (s[i] == 'X' && prev == 'L') {
                ans += 40;
                prev = '-';
                found = true;
                
            }
            else if (s[i] == 'X' && prev == 'C') {
                 ans += 90;
                 prev = '-';
                 found = true;
                
            }
            else if (s[i] == 'C' && prev == 'D') {
                 ans += 400;
                 prev = '-';
                 found = true;
                 
            }
            else if (s[i] == 'C' && prev == 'M') {
                    ans += 900;
                    prev = '-';
                    found = true;
                
                    
            }
            else if (prev == 'I') {
                ans += 1;
                
            }
            else if (prev == 'V') {
                ans += 5;
                    
            }
            else if (prev == 'X') {
                ans += 10;
                    
            }
            else if (prev == 'L') {
                ans += 50;
                
            }
            else if (prev == 'C') {
                ans += 100;
                  
            }
            else if (prev == 'D' ) {
                ans += 500;
                
            }
            else if (prev == 'M') {
                ans += 1000;
            }
            
            if(!found) prev = s[i];
        }
        
        if (!found) {
             if (s[0] == 'I' ) {
                ans += 1;
                  
            }
             if (s[0] == 'V' ) {
                ans += 5;
                    
            }
             if (s[0] == 'X' ) {
                ans += 10;
                   
            }
             if (s[0] == 'L') {
                ans += 50;

            }
             if (s[0] == 'C' ) {
                ans += 100;
                    
            }
             if (s[0] == 'D') {
                ans += 500;
                  
            }
             if (s[0] == 'M') {
                ans += 1000;
                    
            }
        }
        
        return ans;
    }
};