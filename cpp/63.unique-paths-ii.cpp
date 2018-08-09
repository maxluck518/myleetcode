class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0][0]) return 0;
        int h=obstacleGrid.size(),w=obstacleGrid[0].size();
        vector<int> dp(w,0);
        dp[0]=1;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(obstacleGrid[i][j]){
                    dp[j]=0;
                }else if(j>=1) {
                    dp[j]=dp[j-1]+dp[j];
                }
            }
        }
        return dp[w-1];
    }
};
