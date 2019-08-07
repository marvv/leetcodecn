class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        stringstream ss;
        int i = 0;
        int min = 0;
        for (int i =0; i<strs.size(); i++)
        {
            if (strs[i].size() > min) min = strs[i].size();
        }
        
        if (min == 0) return "";
        
        bool stop = false;
        for (int i =0; i<min; i++)
        {
            char tmp = strs[0][i];
            for (int j =0; j<strs.size(); j++)
            {
                if (tmp != strs[j][i])
                {
                    stop = true;
                    break;
                }
            }
            
            if (stop)
            {
                break;
            }
            else 
            {
                ss << tmp;
            }
        }
        
        
        return ss.str();
    }
};