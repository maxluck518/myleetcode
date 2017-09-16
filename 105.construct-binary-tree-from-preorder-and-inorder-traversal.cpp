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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_pre_index = 0;
        if(inorder.size() == 0) 
            return nullptr;
        else
            return bdTree(preorder,inorder,0,inorder.size()-1,root_pre_index);
    }
    TreeNode* bdTree(vector<int>& preorder, vector<int>& inorder,int begin,int end,int &root_pre_index) {
        int mid_index = 0;
        int root_val = 0; 
        vector<int> ::iterator it;

        /* edge judge */
        if(end < begin || root_pre_index >= inorder.size())
            return nullptr;
        else if(end == begin){
            TreeNode *root = new TreeNode(inorder[begin]);
            root_pre_index ++;
            // cout << begin << endl;
            return root;
        }
        /* mid search */
        root_val = preorder[root_pre_index];
        for(int i = begin;i<=end;i++){
            if(root_val == inorder[i]){
                mid_index = i;
                break;
            }
        }
        // cout << root_pre_index << '\t';
        // cout << root_val << '\t';
        // cout << mid_index << endl;
        /* mid build */
        TreeNode *root = new TreeNode(root_val);
        root_pre_index ++;
        /* cout << root_pre_index << endl; */
        root->left = bdTree(preorder,inorder,begin,mid_index-1,root_pre_index);
        root->right = bdTree(preorder,inorder,mid_index+1,end,root_pre_index);

        return root;
    }
};
