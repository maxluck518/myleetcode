class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        if(n == 3) return max(nums[0],max(nums[1],nums[2]));
        int * a = new int[n];
        int * b = new int[n-2];
        a[0] = 0;
        a[1] = nums[n-1];
        b[0] = 0;
        b[1] = nums[n-2];
        for(int i = 2;i<n;i++){
            a[i] = max(a[i-2]+nums[n-i],a[i-1]);
        }
        for(int i = 2;i<n-2;i++){
            b[i] = max(b[i-2]+nums[n-i-1],b[i-1]);
        }
        int res1 = a[n-1];
        int res2 = b[n-3] + nums[0];
        return max(res1,res2);

    }
};
