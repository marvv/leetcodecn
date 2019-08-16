class Solution {
public:
    void dp(vector<string>& res, int n, int left, string tmp)
    {
        if (tmp.size() == n*2 && n == left) 
        {
            res.push_back(tmp);
            return ;
        }
        
        if (tmp.size() == n*2 || n < left) return ;
        
        if (left < n)
        {
            string t(tmp);
            t.push_back('(');
            dp(res, n, left+1, t);
        }
        
        int r = tmp.size() - left;
        if (r < left)
        {
            string t2(tmp);
            t2.push_back(')');
            dp(res, n, left, t2);
        }
       
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n==0) return res;
        dp(res, n, 0, "");
        
        return res;
    }
};