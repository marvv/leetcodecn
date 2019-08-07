class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i =0;
        int j = height.size() - 1;
        
        while (i<j)
        {
            int tmp = min(height[i], height[j]) * (j-i);
            if (max < tmp) max = tmp;
            if (height[i] < height[j])
            {
                i ++ ;
            }
            else 
            {
                j --;
            }
        }
        
        return max;
    }
};