class Solution {
public:
    int reverse(int x) {
        int64_t tmp = x;
        bool f = false;
        if (tmp <0) 
        {
            tmp = tmp * (-1);
            f = true;
        }
        
        int64_t y = 0;
        while (tmp >0)
        {
            int a = tmp % 10;
            tmp = tmp / 10;
            y = y * 10 + a;
        }
        
        if (f) y = y * (-1);
        if (y> INT_MAX || y < INT_MIN)
        {
            return 0;
        }
        return y;
    }
};