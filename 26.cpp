class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        
        while (it != nums.end())
        {
            vector<int>::iterator tmp = it + 1;
            while (tmp != nums.end()  && *tmp == *it)
            {
                tmp = nums.erase(tmp);
            }
            
            it = tmp;
        }
        
        return nums.size();
        
    }
};