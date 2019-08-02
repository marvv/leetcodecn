class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1 || s.empty()) return s;
        
        vector<string> tmp(numRows, "");
        int index = 0;
        int dir = 1;
        for (int i=0; i<s.size();i++)
        {
            tmp[index] = tmp[index] + s[i];
            if (index == 0)
            {
                dir = 1;
            }
            if (index == numRows-1)
            {
                dir = -1;
            }
            index = index + dir;
        }
        
        string result;
        for (int i=0; i<numRows; i++)
        {
            result = result + tmp[i];
        }
        
        return result;
    }
};