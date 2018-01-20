class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const uint32_t MAX = 0x7fffffff;
        const uint32_t MIN = 0x80000000;
        int len = nums.size();
        int min_num = MAX,max_num = MIN;
        bool flag = false;
        int l=1,r=0;
        for(int i = 1;i< len;i++){
            if(nums[i-1] >nums[i])
                flag = true;
            if(flag)
                min_num = min(min_num,nums[i]);
        }
        flag = false;
        for(int i = len - 2;i>=0;i--){
            if(nums[i+1] < nums[i])
                flag = true;
            if(flag)
                max_num = max(max_num,nums[i]);
        }
        // cout << min_num << endl;
        // cout << max_num << endl;
        for(int i = 0;i<len;i++){
            if(nums[i] > min_num){
                l = i;
                break;
            }
        }
        for(int i = len-1;i>=0;i--){
            if(nums[i] < max_num){
                r = i;
                break;
            }
        }
        return l <= r ? r-l+1 : 0;
    }
};
