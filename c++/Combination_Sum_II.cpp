class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if(num.empty()) {
            return ret;
        }
        vector<int> list;
        sort(num.begin(),num.end());
        combHelper(ret,num,list,0,target);
        return ret;
    }
    void combHelper(vector<vector<int> > &ret, vector<int> &num, vector<int> &list,int index,int target) {
        if(target==0) {
            ret.push_back(list);
            return;
        }
        int pre=-1;
        for(int i=index;i<num.size();i++) {
            if(num[i]>target) {
                return;
            } else if(pre==num[i]){
                continue;
            } else if (num[i]<=target){
                list.push_back(num[i]);
                combHelper(ret,num,list,i+1,target-num[i]);
                list.pop_back();
                pre=num[i];
            }
        }
    }
};