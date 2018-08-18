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
        if(root == NULL) return 0;
        int level = 1;
        return bfs(root,level);

    }
    int bfs(TreeNode* root,int level){
        if(!root->left && !root->right){
            return level;
        }
        else{
            int res1 = (root->left == NULL)? 0x7fffffff : bfs(root->left,level+1);
            int res2 = (root->right == NULL)? 0x7fffffff : bfs(root->right,level+1);
            return min(res1,res2);
        }
    }
};

