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
    int minDepth(TreeNode* root) {
        const uint32_t MAX = 0x7fffffff;
        int global = 0;
        mindepth = MAX;
        dfs(root,global);
        return mindepth;
    }
    void dfs(TreeNode* root,int &local){
        if(root == nullptr){
            mindepth = min(local,mindepth);
            return;
        }
        int dfslocal = local + 1;
        if(root->left != nullptr && root->right ==nullptr)
            dfs(root->left,dfslocal);
        else if(root->left == nullptr && root->right !=nullptr)
            dfs(root->right,dfslocal);
        else{
            dfs(root->left,dfslocal);
            dfs(root->right,dfslocal);
        }
    }
private:
    int mindepth;
};
