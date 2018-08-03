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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root_post_index = postorder.size()-1;
        if(inorder.size() == 0) 
            return nullptr;
        else
            return bdTree(inorder,postorder,0,inorder.size()-1,root_post_index);
    }

    TreeNode* bdTree(vector<int>& inorder, vector<int>& postorder, int begin,int end,int &root_post_index) {
        int mid_index = 0;
        int root_val = 0; 
        // cout << begin << '\t' << end << endl;
        // cout << root_post_index << endl;

        /* edge judge */
        if(end < begin || root_post_index < 0)
            return nullptr;
        else if(end == begin){
            TreeNode *root = new TreeNode(inorder[begin]);
            root_post_index --;
            return root;
        }
        /* mid search */
        root_val = postorder[root_post_index];
        for(int i = begin;i<=end;i++){
            if(root_val == inorder[i]){
                mid_index = i;
                break;
            }
        }
        /* mid build */
        TreeNode *root = new TreeNode(root_val);
        root_post_index --;
        /* cout << root_post_index << endl; */
        root->right= bdTree(postorder,inorder,mid_index+1,end,root_post_index);
        root->left= bdTree(postorder,inorder,begin,mid_index-1,root_post_index);

        return root;
    }
};
