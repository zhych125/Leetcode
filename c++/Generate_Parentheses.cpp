class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n==0) {
            return ret;
        }
        string s;
        generateHelper(ret,s,0,0,n);
        return ret;
    }
    void generateHelper(vector<string> &ret,string s, int left,int right,int n) {
        if(right==n) {
            ret.push_back(s);
            return;
        }
        if(left<n) {
            generateHelper(ret,s+"(",left+1,right,n);
        }
        if(right<left) {
            generateHelper(ret,s+")",left,right+1,n);
        }
    }
};