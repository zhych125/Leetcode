class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()||triangle[0].empty()) {
            return 0;
        }
        vector<int> dp(triangle.size(), 0);
        dp[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++) {
            for(int j=triangle[i].size()-1;j>=0;j--) {
                if(j == 0) {
                    dp[j]+=triangle[i][j];
                }
                else if(j==triangle[i].size()-1) {
                    dp[j]=triangle[i][j]+dp[j-1];
                }
                else {
                    dp[j]=min(dp[j-1],dp[j])+triangle[i][j];
                }
            }
        }
        int minimum=dp[0];
        for(int j=1;j<dp.size();j++) {
            minimum=min(minimum,dp[j]);
        }
        return minimum;
    }
};