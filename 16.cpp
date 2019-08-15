class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
                
        if (nums.size() < 3) return 0;
                
        int result = 0;
        int min = INT_MAX;
        
        for (int i =0; i<nums.size()-2;i++)
        {               
            int l = i+1;
            int r = nums.size()-1;
            
            while (l < r)
            {
                int diff = nums[l] + nums[r] + nums[i] - target;
                if (diff == 0) return target;
                
                if (abs(diff) < min)
                {
                    min = abs(diff) ;
                    result = nums[l] + nums[r] + nums[i];
                }
                
                if (diff < 0)
                {
                    l++;
                }
                else 
                {
                    r--;
                }
            }
        }
         
        return result;
    }
};
              
