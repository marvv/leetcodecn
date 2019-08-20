class Solution {
public:
    int f(const vector<int>& nums, int target, bool l)
    {
        int left = 0;
        int right = nums.size();
        
        while (left < right )
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (nums[mid] == target && l))
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int left = f(nums, target, true);
        if (left == nums.size() || nums[left] != target) return res;
        
        int right = f(nums, target, false)-1;
        res[0] = left;
        res[1] = right;
        return res;
    }
};