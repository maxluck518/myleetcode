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
        if(inorder.size() == 0) return NULL;
        int pos = postorder.size()-1;
        return build(pos,0,inorder.size()-1,inorder,postorder);
    }
    TreeNode * build(int &pos,int start,int end,vector<int> inorder,vector<int> postorder){
        if(end < start || pos < 0) return NULL;
        TreeNode* root = new TreeNode(postorder[pos]);
        if(end == start){
            pos --;
            return root;
        }
        int mid = end;
        for(int i = start;i<=end;i++){
            if(inorder[i] == postorder[pos]){
                mid = i;
                break;
            }
        }
        pos --;
        root->right = build(pos,mid+1,end,inorder,postorder);
        root->left = build(pos,start,mid-1,inorder,postorder);
        return root;
    }
};
