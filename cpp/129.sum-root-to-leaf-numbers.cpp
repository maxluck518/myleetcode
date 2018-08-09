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
    int sumNumbers(TreeNode* root) {
        vector<int> array;
        int cnt = 0;
        if(root == NULL) return 0;
        preorder(array,cnt,root);
        for(int i = 0;i< array.size();i++){
            cnt += array[i];
        }
        return cnt;

    }
    void preorder(vector<int> &array,int cnt,TreeNode * root){
        cnt = 10 * cnt + root->val;
        if(root->left == NULL && root->right == NULL){
            array.push_back(cnt);
            return;
        }
        if(root->left != NULL) preorder(array,cnt,root->left);
        if(root->right != NULL) preorder(array,cnt,root->right);
    }
};
