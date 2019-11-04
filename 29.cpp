class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long a = dividend;
        long b = divisor;
        if (a<0) a=(-1) * a;
        if (b<0) b=(-1) * b;
        
        int result = 0;
        int exp = 0;
        while (a >= b) {
            exp = 1;
            long  tmp = b;
            while (tmp << 1 < a ) {
                tmp = tmp << 1;
                exp = exp << 1; 
            }
            result += exp;
            a = a - tmp;
        }
        return !neg ? result : (result * (-1));
    }
};