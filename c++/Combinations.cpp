class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        if(n<1||k<1) {
            return ret;
        }
        vector<int> list;
        combineHelper(n,k,1,ret,list);
        return ret;
    }
    void combineHelper(int &n,int &k, int index, vector<vector<int>> &ret, vector<int> &list) {
        if(list.size()==k) {
            ret.push_back(list);
            return;
        }
        for(int i=index; i<=n;i++) {
            list.push_back(i);
            combineHelper(n,k,i+1,ret,list);
            list.pop_back();
        }
    }
};