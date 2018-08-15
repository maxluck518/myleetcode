class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int a[row+1][col+1];
        memset(a,0,sizeof(int)*(row+1)*(col+1));
        for(int i = 2;i<=row;i++)
            a[i][0] = 0x7fffffff;
        for(int j = 2;j<=col;j++)
            a[0][j] = 0x7fffffff;
        for(int i = 1;i<=row;i++){
            for(int j = 1;j<=col;j++){
                a[i][j] = min(a[i-1][j],a[i][j-1]) + grid[i-1][j-1];
            }
        }
        return a[row][col]; 
        
    }
};
