class Solution {
public:
    string addBinary(string a, string b) {
        stringstream ss;
        int plus1 = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >=0 && j >=0) {
            int tmp = plus1 + a[i]-'0' + b[j]-'0';
            i--;
            j--;
            if (tmp < 2) {
                ss << tmp;
                plus1 = 0;
            } else  {
                ss << tmp - 2;
                plus1 = 1;
            } 
        }
        
        while (i>=0) {
            int tmp = plus1 + a[i]-'0';
            i--;     
            if (tmp < 2) {
                ss << tmp;
                plus1 = 0;
            } else  {
                ss << tmp - 2;
                plus1 = 1;
            } 
        }
        
        while (j>=0) {
            int tmp = plus1 + b[j]-'0';
            j--;
            if (tmp < 2) {
                ss << tmp;
                plus1 = 0;
            } else  {
                ss << tmp - 2;
                plus1 = 1;
            } 
        }
        
        if (plus1) {
            ss << 1;
        }
        
        string s = ss.str();
        reverse(s.begin(), s.end());
        return s;
    }
};