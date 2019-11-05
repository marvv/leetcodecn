class Solution {
public:
    string f(int n) {
        stringstream ss;
        int a = n / 100;
        int b = n % 100;
        string str[] = {"One", "Two", "Three", "Four", "Five", "Six","Seven","Eight","Nine"};
        if (a >0) {
            ss << str[a-1] << " Hundred ";
        }
        
        string s2[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string s3[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety"};
        if (b >= 10 && b<20) {
            ss << s2[b-10] << " ";
            n = 0;
        } else if (b<10 && b>0) {
            ss << str[b-1] << " ";
            n = 0;
        } else if (b >=20) {
            ss << s3[b/10-2] << " ";
            if (b%10) {
                n = b%10;
            }
        }
        
        int c = n % 10;
        if (c) {
            ss << str[c-1] << " ";
        }
        
        return ss.str();
    }
    
    string numberToWords(int num) {
        if (num==0) return "Zero";
        int bill = pow(10, 9);
        int mill = pow(10, 6);
        int thou = pow(10,3);
        stringstream ss;
        if (num >= bill) {
            int n = num / bill;
            num = num % bill;
            ss << f(n) << "Billion ";
        }
        
        if (num >= mill) {
            int n = num / mill;
            num = num % mill;
            ss << f(n) << "Million ";
        }
        
        if (num >= thou) {
            int n = num / thou;
            num = num % thou;
            ss << f(n) << "Thousand ";
        }
        
        if (num) {
            ss << f(num);
        }
        
        string res = ss.str();
        if (res.size() >0) {
            res.resize(res.size()-1);
        }
        return res;
    }
};