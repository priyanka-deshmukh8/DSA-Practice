class Solution {
public:
    int m , n;
    int a[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
         memset(a,-1,sizeof(a));
        return solve(obstacleGrid,0,0);

    }

    int solve(vector<vector<int>>& grid, int i , int j){
        if(i >= m || j >= n || grid[i][j]==1){
           return 0;
        }
        if(i == m-1 && j== n-1)
        {
            return 1;
        }
        if(a[i][j] != -1)
        {
            return a[i][j];
        }

        int right = solve(grid,i,j+1);
        int down = solve(grid,i+1,j);

       

        return a[i][j] = right+down;
    }
};