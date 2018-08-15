class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int * a = new int[n+1];
        a[0] = 0;
        a[1] = nums[nums.size()-1];
        for(int i = 2;i<=n;i++){
            a[i] = max(a[i-1],nums[n-i] + a[i-2]);
        }
        return a[n];
    }
};
