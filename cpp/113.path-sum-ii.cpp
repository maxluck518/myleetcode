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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return result;
        target = sum;
        int global = 0;
        vector<int> globaltrace;
        dfs(root,global,globaltrace);
        return result;
    }
    void dfs(TreeNode* root,int &sum,vector<int> &trace){
        if(root == nullptr) return;
        if(root != nullptr && root->left == nullptr && root->right == nullptr){
            sum = sum + root->val;
            trace.push_back(root->val);
            if(sum == target){
                // if(myhash.find(trace) == myhash.end()){
                    result.push_back(trace);
                    // myhash.insert(pair<vector<int>,int>(trace,1));
                // }
            }
            return;
        }
        trace.push_back(root->val);
        int localsum_l = sum + root->val;
        vector<int> localtrace_l(trace);
        dfs(root->left,localsum_l,localtrace_l);

        int localsum_r = sum + root->val;
        vector<int> localtrace_r(trace);
        dfs(root->right,localsum_r,localtrace_r);
    }
private:
    vector<vector<int>> result;
    // map<vector<int>,int> myhash;
    int target;
};
