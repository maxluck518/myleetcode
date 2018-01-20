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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        bool result = abs(getdepth(root->left) - getdepth(root->right)) <=1 ? true:false;
        if(result)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }
    int getdepth(TreeNode * root){
        if(root == nullptr)
            return 0;
        else
            return max(getdepth(root->left),getdepth(root->right)) + 1;
    }
};
