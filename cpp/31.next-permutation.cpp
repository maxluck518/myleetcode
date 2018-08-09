class Solution {
public:
    void swap(int &a,int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void reverse(vector<int> &nums,int start,int end){
        while(end > start){
            swap(nums[end],nums[start]);
            start ++;
            end --;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        for(int i = nums.size()-2;i>=0;i--){
            int pos = nums.size()-1;
            if(nums[i+1] > nums[i]){
                for(int j = i+1;j<nums.size();j++){
                    if(nums[j] <= nums[i]){
                        pos = j-1;
                        break;
                    }
                }
                swap(nums[i],nums[pos]);
                reverse(nums,i+1,nums.size()-1);
                return ;
            }
        }
        reverse(nums,0,nums.size()-1);
    }
};
