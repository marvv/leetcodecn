class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> tmp;
        for (int i=0; i<nums.size(); i++)
        {
            tmp[nums[i]] = i;
        }
        
        for (int i=0; i<nums.size();i++)
        {
            int x = nums[i];
            if (tmp.find(target-x) != tmp.end() && i!= tmp[target-x])
            {
                result.push_back(i);
                result.push_back(tmp[target-x]);
                break;
            }
        }
        return result;
    }
};