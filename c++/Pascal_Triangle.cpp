class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows<1) {
            return ret;
        }
        vector<int> list(1,1);
        ret.push_back(list);
        for(int i=2;i<=numRows;i++) {
            for(int j=1;j<i-1;j++) {
                list[j]=ret[i-2][j-1]+list[j];
            }
            list.push_back(1);
            ret.push_back(list);
        }
        return ret;
    }
};