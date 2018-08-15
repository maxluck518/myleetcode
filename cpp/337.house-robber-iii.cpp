/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct profit{
    int p1;
    int p2;
    profit(int x,int y) : p1(x),p2(y) {}
}profit;

class Solution {
public:
    int rob(TreeNode* root) {
        profit res = get_profit(root);
        return max(res.p1,res.p2);
    }
    profit get_profit(TreeNode* root){
        profit res(0,0);
        if(root == NULL) return res;
        profit res1 = get_profit(root->left);
        profit res2 = get_profit(root->right);
        res.p1 = root->val + res1.p2 + res2.p2;
        res.p2 = max(res1.p1,res1.p2) + max(res2.p1,res2.p2);
        return res;
    }
};
