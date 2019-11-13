class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }

            if (count >0) {
                nums[i-count] = nums[i];
            }
        }

        if (count) {
            for (int i=0; i<count; i++) {
                nums[nums.size()-1-i] = 0;
            }
        }
    }
};