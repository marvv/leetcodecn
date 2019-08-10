class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        
        while (num >= 1000)
        {
            num = num - 1000;
            ss << "M";
        }
        
        if (num >= 900)
        {
            num = num - 900;
            ss << "CM";
        }  
        
        if (num >= 500)
        {
            num = num - 500;
            ss << "D";
        }
        
        if (num >= 400)
        {
            num = num - 400;
            ss << "CD";
        }
        
        while (num >= 100)
        {
            num = num - 100;
            ss << "C";
        }
        
        if (num >=90)
        {
            num = num - 90;
            ss << "XC";
        }
        
        if (num >= 50)
        {
            num = num - 50;
            ss << "L";
        }
        
        if (num >= 40)
        {
            num = num - 40;
            ss << "XL";
        }
        
        while (num >= 10)
        {
            num = num - 10;
            ss << "X";
        }
        
        if (num ==9)
        {
            num = num - 9;
            ss << "IX";
        } 
        
        if (num >=5)
        {
            num = num - 5;
            ss << "V";
        }
        
        if (num == 4)
        {
            num = 0;
            ss << "IV";
        }
        
        while (num >0)
        {
            ss << "I";
            num = num - 1;
        }
        
        return ss.str();
    }
};