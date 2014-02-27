class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> set;
        ret.push_back(set);
        if(S.empty()) {
            return ret;
        }
        sort(S.begin(),S.end());
        subsetsHelper(S,0,set,ret);
        return ret;
    }
    void subsetsHelper(vector<int> &S,int index, vector<int> &set, vector<vector<int> > &ret) {
        if(index>=S.size()) {
            return;
        }
        for(int i=index;i<S.size();i++) {
            set.push_back(S[i]);
            ret.push_back(set);
            subsetsHelper(S,i+1,set,ret);
            set.pop_back();
        }
    }
};