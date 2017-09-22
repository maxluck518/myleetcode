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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return result;
        if(root != nullptr && root->left == nullptr && root->right ==nullptr){
            string global_trace = getschar(root->val);
            result.push_back(global_trace);
        }
        string global_trace1;
        string global_trace2;
        global_trace1 = getschar(root->val);
        global_trace2 = getschar(root->val);
        dfs(root->left,global_trace1);
        dfs(root->right,global_trace2);
        return result;
    }
    void dfs(TreeNode* root,string &trace){
        if(root == nullptr)
            return;
        if(root != nullptr && root->left == nullptr && root->right ==nullptr){
            trace = trace + "->" + getschar(root->val);
            result.push_back(trace);
            return;
        }
        string c = getschar(root->val);
        trace = trace + "->" + getschar(root->val);
        string trace_l(trace);
        string trace_r(trace);
        dfs(root->left,trace_l);
        dfs(root->right,trace_r);
    }
    string getschar(int val){
        string s;
        stack<int> str;
        if(val<0)
            s.push_back('-');
        val = abs(val);
        while(val != 0){
           str.push(val%10);
           val = val/10;
        }
        while(!str.empty()){
            s.push_back((char)(str.top() + 48));
            str.pop();
        }
        return s;
    }
private:
    vector<string> result;
};
