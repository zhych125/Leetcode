class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        unordered_map<char,int> existed;
        int begin=0;
        int maxLen=0;
        for(int i=0;i<s.size();i++) {
            if(existed.find(s[i])==existed.end()) {
                existed[s[i]]=i;
                maxLen=max(maxLen,i-begin+1);
            }
            else {
                int previous=existed[s[i]];
                for(int j=begin;j<previous;j++) {
                    existed.erase(s[j]);
                }
                begin=previous+1;
                existed[s[i]]=i;
            }
        }
        return maxLen;
    }
};