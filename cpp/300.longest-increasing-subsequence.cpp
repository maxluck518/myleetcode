class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int *a = new int[n];
        int res = 0x80000000;
        for(int i = n-1;i>=0;i--){
            a[i] = 1;
            for(int j = i+1;j<n;j++){
                if(nums[i] < nums[j]){
                   a[i] = max(a[i],a[j]+1);
                }
            }
        }
        for(int i = 0;i<n;i++){
            res = max(res,a[i]);
        }
        return res;
    }
};
