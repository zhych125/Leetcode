class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) {
            return false;
        }
        int len=s1.size();
        vector<vector<vector<bool>>> dp(len,vector<vector<bool>>(len,vector<bool>(len+1,false)));
        for(int i=len-1;i>=0;i--) {
            for(int j=len-1;j>=0;j--) {
                for(int k=1;k<=len-i&&k<=len-j;k++) {
                    if(s1.substr(i,k)==s2.substr(j,k)) {
                        dp[i][j][k]=true;
                    }
                    else {
                        for(int l=1;l<k;l++) {
                            if((dp[i][j][l]&&dp[i+l][j+l][k-l])||(dp[i][j+k-l][l]&&dp[i+l][j][k-l])) {
                                dp[i][j][k]=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][len];
    }
};