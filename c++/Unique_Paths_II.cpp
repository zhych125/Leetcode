class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0].empty()) {
            return 0;
        }
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<obstacleGrid.size();i++) {
            for(int j=0;j<obstacleGrid[0].size();j++) {
                if(i==0&&j==0) {
                    dp[0][0]=obstacleGrid[0][0]?0:1;
                } else if(i==0) {
                    dp[i][j]=obstacleGrid[0][j]?0:dp[0][j-1];
                } else if(j==0) {
                    dp[i][j]=obstacleGrid[i][0]?0:dp[i-1][0];
                } else {
                    dp[i][j]=obstacleGrid[i][j]?0:dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};