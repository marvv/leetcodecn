class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return string("1");
        string s = countAndSay(n-1);
        int count = 0;
        char tmp ;
        stringstream  ss;
        for (int i=0; i<s.size();i++) {
            if (i==0) {
                tmp = s.at(i);
            }
            if (tmp != s.at(i)) {
                ss << count << tmp;
                tmp = s.at(i);
                count = 1;
            } else {
                count++;
            }
        }
        ss << count << tmp;
        return ss.str();
    }
};