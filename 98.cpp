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
    void f(vector<int>&x, TreeNode* root)
    {
        if (root == NULL) return;
        f(x, root->left);
        x.push_back(root->val);
        f(x, root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> x;
        f(x, root);
        for (int i =0;i<x.size()-1;i++) {
            if (x[i] >= x[i+1]) {
                return false;
            }
        }
        return true;
    }
};