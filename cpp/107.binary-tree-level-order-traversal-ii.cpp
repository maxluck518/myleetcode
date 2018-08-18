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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        int level = 1;
        bfs(root,res,level);
        reverse(res.begin(),res.end());
        return res;
    }
    void bfs(TreeNode* root,vector<vector<int>> &res,int level){
        if(root == NULL) return;
        if(level > res.size()){
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
        }
        else{
            res[level-1].push_back(root->val);
        }
        bfs(root->left,res,level+1);
        bfs(root->right,res,level+1);
    }
};

