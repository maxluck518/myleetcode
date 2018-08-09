class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size()-1;
            int high, res = 0;
            while(l<r){
                high = min(height[l],height[r]);  
                res = high*(r-l)>res?high*(r-l):res;
                if(height[l]<=height[r]){
                    ++l;
                }else{
                    --r;
                }
            }     
            return res;
        }
};
