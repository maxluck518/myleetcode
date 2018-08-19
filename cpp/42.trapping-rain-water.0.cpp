// my dp
// class Solution {
// public:
    // int trap(vector<int>& height) {
        // int n = height.size();
        // int res = 0;
        // if(n<=2) return res;
        // vector<int> left(n);
        // vector<int> right(n);
        // left[0] = height[0];
        // for(int i = 1;i<n;i++){
            // left[i] = max(left[i-1],height[i]);
        // }
        // right[n-1] = height[n-1];
        // for(int i = n-2;i>=0;i--){
            // right[i] = max(right[i+1],height[i]);
        // }
        // for(int i = 0;i<n;i++){
            // res += min(right[i],left[i]) - height[i];
        // }
        // return res;
    // }
// };
// my 2 pointers

class Solution {
    public:
        int trap(vector<int>& height)
        {
            int left = 0, right = height.size() - 1;
            int ans = 0;
            int left_max = 0, right_max = 0;
            while (left < right) {
                if (height[left] < height[right]) {
                    height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                    ++left;
                }
                else {
                    height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                    --right;
                }
            }
            return ans;
        }
};
