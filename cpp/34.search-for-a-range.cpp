class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if(nums.empty()){
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        return searchTarget(nums,target,0,nums.size()-1);
    }

    vector<int> searchTarget(vector<int>& nums, int target,int start,int end) {
        vector<int> ret;
        if(end == start){
            if(nums[start] == target){
                ret.push_back(start);
                ret.push_back(start);
            }
            else{
                ret.push_back(-1);
                ret.push_back(-1);
            }
            return ret; 
        }
        else if(end < start){
            ret.push_back(-1);
            ret.push_back(-1);
            return ret; 
        }

        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            return midSearch(nums,mid,target);
        }
        else if(nums[mid] > target){
            return searchTarget(nums,target,start,mid-1);
        }
        else{
            return searchTarget(nums,target,mid+1,end);
        }
    }

    vector<int> midSearch(vector<int>& nums, int mid,int target){
        int left = mid - 1;
        vector<int> ret;
        while(left >= 0){
            if(nums[left] == target)
                left --;
            else
                break;
        }

        int right = mid + 1;
        while(right < nums.size()){
            if(nums[right] == target)
                right ++;
            else
                break;
        }
        ret.push_back(left + 1);
        ret.push_back(right - 1);
        return ret;
    }
};
