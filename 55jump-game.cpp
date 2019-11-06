class Solution {
public:
    bool f(vector<int>& nums, int index) {
        if (index >= nums.size()-1) return true;
        int maxIndex = index;
        int nextIndex = index;
        for (int i=1; i<=nums[index];i++) {
            if (index+i >=nums.size()-1) {
                return true;
            } 
            
            if (maxIndex < index +i + nums[index+i]) {
                nextIndex = index+i;
                maxIndex = index + i + nums[index+i];
                if (maxIndex>=nums.size()-1) {
                    return true;
                }
            }
        }
        if (nextIndex == index) return false;
        return f(nums, nextIndex);
        
    }
    
    bool canJump(vector<int>& nums) {
        return f(nums, 0);
    }
};