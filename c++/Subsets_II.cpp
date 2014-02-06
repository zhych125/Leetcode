class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> ret;
        vector<int> sset;
        ret.push_back(sset);
        if(S.empty()) {
            return ret;
        }
        sort(S.begin(),S.end());
        subsetsHelper(S,ret,sset,0);
        return ret;
    }
    void subsetsHelper(vector<int> &S, vector<vector<int>> &ret, vector<int>& sset, int cursor) {
        for(int i=cursor;i<S.size();i++) {
            if(i==cursor||S[i-1]!=S[i]) {
                sset.push_back(S[i]);
                ret.push_back(sset);
                subsetsHelper(S,ret,sset,i+1);
                sset.pop_back();
            }
        }
    }
};