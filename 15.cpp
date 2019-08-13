class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        if (nums.size() < 3) return result;
        
        map<int, bool> hit;
        
        for (int i =0; i<nums.size()-2;i++)
        {
            if (nums[i] > 0) break;
            
            if (hit.count(nums[i]) > 0) continue;
            
            hit.insert(make_pair(nums[i], true));
            
            int l = i+1;
            int r = nums.size()-1;
            
            while (l < r)
            {
                if (nums[l] + nums[r] + nums[i] == 0)
                {
                    vector<int> tmp{nums[i], nums[l], nums[r]};
                    result.push_back(tmp);
                    do {l++;} while (l<r && nums[l] == nums[l-1]);
                    do {r--;} while (l<r && nums[r] == nums[r+1]);
                }
                else if (nums[l] + nums[r] + nums[i] < 0)
                {
                    do {l++;} while (l<r && nums[l] == nums[l-1]);
                }
                else 
                {
                    do {r--;} while (l<r && nums[r] == nums[r+1]);

                }
            }
        }
        
        
        return result;
    }
};