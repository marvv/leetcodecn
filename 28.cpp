class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;
        
        for (int i =0; i<haystack.size(); i++)
        {
            if (haystack.size() - i < needle.size()) return -1;
            
            if (haystack[i] == needle[0])
            {
                bool match = true;
                for (int j = 0;j<needle.size(); j++)
                {
                    if (haystack[i+j] != needle[j])
                    {
                        match = false;
                    }
                }
                if (match) return i;
            }
        }
        
        return -1;
    }
};