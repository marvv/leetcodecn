class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i=0; i<s.size();i++)
        {   
            if (s[i] == 'C' && i < s.size() -1 && s[i+1] == 'M')
            {
                result += 900;
                i++;
                continue;
            }
            
            if (s[i] == 'C' && i < s.size() -1 && s[i+1] == 'D')
            {
                result += 400;
                i++;
                continue;
            }
            
            if (s[i] == 'X' && i < s.size() -1 && s[i+1] == 'C')
            {
                result += 90;
                i++;
                continue;
            }
            
            if (s[i] == 'X' && i < s.size() -1 && s[i+1] == 'L')
            {
                result += 40;
                i++;
                continue;
            }        
            if (s[i] == 'I' && i < s.size() -1 && s[i+1] == 'X')
            {
                result += 9;
                i++;
                continue;
            } 
            if (s[i] == 'I' && i < s.size() -1 && s[i+1] == 'V')
            {
                result += 4;
                i++;
                continue;
            } 
            if (s[i] == 'M')
            {
                result += 1000;
                continue;
            }
            if (s[i] == 'D')
            {
                result += 500;
                continue;
            }
             if (s[i] == 'C')
            {
                result += 100;
                continue;
            }
            if (s[i] == 'L')
            {
                result += 50;
                continue;
            }
            if (s[i] == 'X')
            {
                result += 10;
                continue;
            }
            if (s[i] == 'V')
            {
                result += 5;
                continue;
            }     
            if (s[i] == 'I')
            {
                result += 1;
                continue;
            } 
        }
        
        return result;
    }
};