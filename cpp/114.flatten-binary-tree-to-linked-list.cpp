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
    void flatten(TreeNode* root) {

        
    }
    void preorder(TreeNode *root){
        if(root == nullptr)
        TreeNode *left = preorde(root->left);
        root->right = left;
        TreeNode *right = preorde(root->right);
    }
};
