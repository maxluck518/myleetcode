/* dfs time exceed */
// class Solution {
// public:
    // int jump(vector<int>& nums) {
        // return dfs(0,0,nums);
    // }
    // int dfs(int pos,int cnt,vector<int> nums){
        // if(pos >= nums.size()-1) return cnt;
        // cnt ++;
        // int min_t = 0x7fffffff;
        // for(int i = 1;i<=nums[pos];i++){
            // min_t = min(min_t,dfs(pos+i,cnt,nums));
        // }
        // return min_t;
    // }
// };

/* dfs space exceed */
// class Solution {
// public:
    // int jump(vector<int>& nums) {
        // int cnt = 0;
        // int pos = 0;
        // dfs(pos,cnt,nums);
        // return cnt;
    // }
    // void dfs(int &pos,int &cnt,vector<int> nums){
        // if(pos >= nums.size()-1) return ;
        // cnt ++;
        // int max_t = 0x80000000;
        // int new_pos = pos;
        // for(int i = 1;i<=nums[pos];i++){
            // if(i+pos >= nums.size()-1){
                // return ;
            // }
            // else if(max_t < i+nums[pos+i]){
                // max_t = i+nums[pos+i];
                // new_pos = pos+i;
            // }

        // }
        // pos = new_pos;
        // dfs(pos,cnt,nums);
    // }
// };

/* dfs greedy*/
// class Solution {
// public:
    // int jump(vector<int>& nums) {
        // int cnt = 0;
        // int pos = 0;
        // while(pos < nums.size()-1){
            // cnt++;
            // int max_t = 0x80000000;
            // int new_pos = pos;
            // for(int i = 1;i<=nums[pos];i++){
                // if(i+pos >= nums.size()-1){
                    // return cnt;
                // }
                // else if(max_t < i+nums[pos+i]){
                    // max_t = i+nums[pos+i];
                    // new_pos = pos+i;
                // }
                // cout << i+pos << endl;
            // }
            // pos = new_pos;
        // }
        // return cnt;
    // }
// };
/* dfs fast greedy*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0, snum=0, nlen=nums.size();
        if (nlen<=1) return 0;
        while (step+nums[step]<nlen-1){
            int imax=step, vmax=0;
            for (int i=1; i<=nums[step]; i++)
                if (nums[step+i]+i>vmax) vmax=nums[step+i]+i, imax=i;
            step+=imax, snum++;
        }
        return ++snum;
    }
};
