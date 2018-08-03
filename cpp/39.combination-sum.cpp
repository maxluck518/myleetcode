class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        global_target = target;
        sort(candidates.begin(),candidates.end());
        edge = target%candidates[0] == 0?  target/candidates[0] : target/candidates[0] + 1;
        int sum = 0;
        vector<int> trace;
        dfs(candidates,0,sum,0,trace);
        return result;
    }
    void dfs(vector<int> &candidates,int k,int &sum,int pos,vector<int> &trace){
        if(sum == global_target) {
            result.push_back(trace);
            return;
        }
        else if(k<=edge && sum < global_target){
            for(int i = pos;i<candidates.size();i++){
                trace.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates,k+1,sum,i,trace);
                trace.pop_back();
                sum -= candidates[i];
            }
        }
    }
private:
    vector<vector<int>> result;
    int global_target;
    int edge;
};
