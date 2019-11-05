/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    void f(int pre, int& sum, TreeNode* node)
    {
        if (node == NULL) return ;
        if (node->left == NULL && node->right==NULL) 
        {
            sum = pre*10 + node->val;
            return ;
        }
        
        pre = pre*10 + node->val;
        int sum1 = 0;
        int sum2 = 0;
        f(pre, sum1, node->left);
        f(pre, sum2, node->right);
        sum = sum1+sum2+sum;
    }
    
    int sumNumbers(TreeNode* root) {
        int pre=0;
        int sum = 0;
        f(pre, sum, root);
        return sum;
    }
};