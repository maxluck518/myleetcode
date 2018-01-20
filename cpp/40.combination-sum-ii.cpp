class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        global_target = target;
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<int> trace;
        dfs(candidates,0,sum,trace);
        return result;
    }
    void dfs(vector<int> &candidates,int k,int &sum,vector<int> &trace){
        if(sum == global_target) {
            if(myhash.find(trace) == myhash.end()){
                result.push_back(trace);
                myhash.insert(pair<vector<int>,int>(trace,1));
            }
            return;
        }
        else if(sum < global_target){
            for(int i = k;i<candidates.size();i++){
                trace.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates,i+1,sum,trace);
                trace.pop_back();
                sum -= candidates[i];
            }
        }
    }
private:
    vector<vector<int>> result;
    int global_target;
    map<vector<int>,int> myhash;
};
