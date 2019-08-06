class Solution {
public:
    bool isPalindrome(int x) {
        if (x <0) return false;
        stack<int> st;
        queue<int> q;
        int tmp = x;
        while (tmp >0)
        {
            int x = tmp % 10;
            tmp = tmp / 10;
            st.push(x);
            q.push(x);
        }
        
        while (!q.empty())
        {
            if (q.front() != st.top()) return false;
            q.pop();
            st.pop();
        }
        
        return true;
    }
};