class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        dfs(res,nums,0);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &nums, int j) {  
        if (j == nums.size()) {  
            vector<int> temp; 
            for(int i = 0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            res.push_back(temp);  
        }  
        for (int i = j; i < nums.size(); i++) {  
            swap(nums, i, j);  
            dfs(res, nums, j+1);  
            swap(nums, i, j);  
        }  
    }  
    void swap(vector<int> &nums, int m, int n) {  
        int temp = nums[m];  
        nums[m] = nums[n];  
        nums[n] = temp;  
    }  
};

