class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0;
        int i = nums.size() -1;
        for (; i>= 1; i--) {
            if (nums[i] > nums[i-1]) {
                index = i -1;
                break;
            }
        }
        
        if (i == 0) {
            sort(nums.begin(), nums.end());
        } else {
            sort(nums.begin() + index +1, nums.end());
            for (int j = index+1; j < nums.size(); j++) {
                if (nums[j] > nums[index]) {
                    int tmp = nums[j];
                    nums[j] = nums[index];
                    nums[index] = tmp;
                    break;
                }
            }
        }
        
    }
};