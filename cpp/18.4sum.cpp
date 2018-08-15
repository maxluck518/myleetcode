class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> ress;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int t = target - nums[i] - nums[j];
                int pos1 = j+1;
                int pos2 = n-1;
                while(pos2 > pos1){
                    if(nums[pos1] + nums[pos2] > t){
                        pos2 --;
                    }
                    else if(nums[pos2] + nums[pos1] < t){
                        pos1 ++;
                    }
                    else{
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[pos1]);
                        tmp.push_back(nums[pos2]);
                        if(ress.find(tmp) == ress.end())
                            ress.insert(tmp);
                        pos1 ++;
                        pos2 --;
                    }
                }
            }
        }
        set<vector<int>> ::iterator it;
        for(it = ress.begin();it != ress.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
