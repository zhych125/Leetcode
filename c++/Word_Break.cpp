class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()||dict.empty()) {
            return false;
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<s.size()+1;i++){
            for(int j=i;j>=1;j--) {
                if(dp[j-1]) {
                    if(dict.find(s.substr(j-1,i-j+1))!=dict.end()) {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};