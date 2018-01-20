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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        int max_len = ComputeBianryTreeLength(root,max);
        return max;
    }
    int ComputeBianryTreeLength(TreeNode *root,int &max){
        if(root == nullptr)
            return 0;
        else {
            int left_len = ComputeBianryTreeLength(root->left,max);
            int right_len = ComputeBianryTreeLength(root->right,max);
            int len = left_len + right_len;
            max = (max > len)?max:len;
            return (left_len > right_len)?left_len+1:right_len+1;
        }
    }
};
