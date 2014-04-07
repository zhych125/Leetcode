class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) {
            return false;
        }
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++) {
            int singleDigit=s[i-1]-'0';
            int doubleDigits=0;
            if(i>1) {
                doubleDigits=atoi(s.substr(i-2,2).c_str());
            }
            if(singleDigit!=0) {
                dp[i]+=dp[i-1];
            }
            if(doubleDigits>=10&&doubleDigits<=26) {
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
  
};