// class Solution {
// public:
    // int threeSumClosest(vector<int>& nums, int target) {
        // if(nums.size() < 3) return 0;
        // int res = 0x7fffffff;
        // for(int h = 0;h<nums.size() - 2;h++){
            // int l = h + 1;
            // int r = nums.size() - 1;
            // while(r>l){
                // int tos = nums[l] + nums[r] + nums[h] - target ;
                // if(tos > 0){
                    // if(nums[l] > nums[r]){
                        // l ++;
                    // }
                    // else{
                        // r--;
                    // }
                // }
                // else if(tos < 0){
                    // if(nums[l] > nums[r]){
                        // r--;
                    // }
                    // else{
                        // l++;
                    // }
                // }
                // else{
                    // return target;
                // }
                // if(abs(tos) < abs(res))
                    // res = tos;
                // cout << tos << endl;
            // }
        // }
        // return res + target;
    // }
// };

class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    int closest = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first+1;
        int third = nums.size()-1;            
        while(second < third) {
            int curSum = nums[first]+nums[second]+nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}
};
