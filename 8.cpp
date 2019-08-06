class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int64_t tmp = 0;
        int begin = 0;
        bool f = false;
        for (int i=0;i<str.size();i++)
        {
            if (str[i] != ' ')
            {
                begin = i;
                break;
            }
        }

        if (!(str[begin]<='9' && str[begin]>='0') && str[begin]!= '-' && str[begin]!= '+') return 0;

        int end = begin;
        for (int i = begin+1; i<str.size();i++)
        {
            if (str[i] >= '0' && str[i] <='9')
            {
                end = i;
            } else {
                end = i-1;
                break;
            }
        }

        if (str[begin] == '+')
        {
            begin ++;
        } else if (str[begin] == '-')
        {
            begin ++;
            f = true;
        }

        while (begin <= end)
        {
            tmp = tmp * 10 + str[begin] - '0';
            begin ++;

            if (tmp > INT_MAX)
            {
                break;
            }
        }

        if (f)
        {
            tmp = tmp * (-1);
        }

        if (tmp > INT_MAX)
        {
            return INT_MAX;
        }
        if (tmp < INT_MIN)
        {
            return INT_MIN;
        }

        return tmp;
    }
};