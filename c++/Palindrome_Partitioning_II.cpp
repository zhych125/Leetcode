class Solution {
public:
    int minCut(string s) {
        if(s.size()<2) {
            return 0;
        }
        vector<int> dp;
        for(int i=0;i<=s.size();i++) {
            dp.push_back(s.size()-i);
        }
        vector<vector<bool> > palindrome(s.size(),vector<bool>(s.size(),false));
        for(int i=s.size()-1;i>=0;i--) {
            for(int j=i;j<s.size();j++) {
                if(s[i]==s[j]&&((j-i)<2||palindrome[i+1][j-1])) {
                    palindrome[i][j]=true;
                    dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
        }
        return dp[0]-1;
    }
};