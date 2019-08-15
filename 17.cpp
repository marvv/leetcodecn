class Solution {
public:
    void f(map<char, string>& mp, string tmp, const string& digits, int index, vector<string>& res)
    {
        if (tmp.size() == digits.size())
        {
            res.push_back(tmp);
            return;
        }
        
        char cur = digits[index];
        string s = mp[cur];
        for (int i =0; i<s.size(); i++)
        {
            string t = tmp;
            t.push_back(s[i]);
            f(mp, t, digits, index+1, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty()) return res;
        
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        f(mp, "", digits, 0, res);
        return res;
    }
};