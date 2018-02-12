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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) 
            return false;
        target = sum;
        result = false;
        int global_set = 0;
        dfs(root,global_set);
        return result;
    }
    void dfs(TreeNode * root,int &sum){
        if(root == nullptr){
            if(!result)
                result = sum == target?true:false;
        }
        else{
            int local_set = sum + root->val;
            if(root->left != nullptr && root->right == nullptr)
                dfs(root->left,local_set);
            else if(root->left == nullptr && root->right != nullptr)
                dfs(root->right,local_set);
            else{
                dfs(root->left,local_set);
                dfs(root->right,local_set);
            }
        }
    }
private:
    int target;
    bool result;
};
