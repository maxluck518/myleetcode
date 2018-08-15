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
        if(root != NULL)
            dfs(root);
    }
    TreeNode* dfs(TreeNode* root){
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* leaf = root;
        root -> left = NULL;
        if(l != NULL){
            leaf->right = l;
            leaf = dfs(l);
        }
        if(r != NULL){
            leaf->right = r;
            leaf = dfs(r);
        }
        return leaf;
    }
};
