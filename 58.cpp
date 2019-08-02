class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int len = 0;
        int index = 0;
        for (int i = s.size() -1 ; i>=0; i--)
        {
            if (s[i] != ' ') 
            {
                index = i;
                break;
            }
        }
        
        for (int j = index; j>=0; j--)
        {
            if (s[j] != ' ') 
            {
                len ++;
            }
            else 
            {
                break;
            }
        }
        return len;
    }
};