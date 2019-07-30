class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int len = 0;
        map<char, int> mp;
        int start = 0;
        int end = 0;
        for (int i=0; i<s.length();i++)
        {
            char c = s.at(i); 
            if (mp.find(c) == mp.end() || mp[c] < start)
            {
                end = i;
                mp[c] = i;
            }
            else
            {
                int tmp = end - start + 1;
                if (tmp > len)
                {
                    len = tmp;
                }
                start = mp[c] + 1;
                mp[c] = i;
                end = i;
            }
        }
        
        if (end - start + 1 > len)
        {
            len = end - start + 1;
        }
        
        return len;
    }
};