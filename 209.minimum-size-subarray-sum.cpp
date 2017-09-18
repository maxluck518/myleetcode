class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const uint32_t MAX = 0x7fffffff;
        int len = nums.size();
        if(len == 0) return 0;
        int start = 0,end = 0;
        int min_len = MAX;
        int sum = nums[0];
        int local_len = MAX;
        while(end < len){
            if(sum >= s){
                local_len = end - start + 1;
                min_len = min_len < local_len? min_len : local_len;
                sum -= nums[start];
                start ++;
            }
            else{
                end ++;
                sum += nums[end];
            }
        }
       return min_len == MAX? 0:min_len; 
    }
};

