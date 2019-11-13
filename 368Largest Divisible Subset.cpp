class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int end = -1;
        int max = -1;
        vector<int> dp(size,1), pre(size, -1);
        
        for (int i =0; i<nums.size();i++) {
            for (int j=0;j<i;j++) {
                if (nums[i] % nums[j]==0 && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            
            if (max < dp[i]) {
                max = dp[i];
                end = i;
            }
        }
        
        for(int i = end;i!=-1;i = pre[i]){
            res.push_back(nums[i]);
        }
        
        return res;
    }
};