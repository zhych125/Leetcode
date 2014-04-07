class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.empty()) {
            return ret;
        }
        permHelper(num,ret,0);
        return ret;
        
    }
    void permHelper(vector<int> &num, vector<vector<int> > &ret, int index) {
        if(index==num.size()-1) {
            ret.push_back(num);
            return;
        } else {
            for(int i=index;i<num.size();i++) {
                swap(num,index,i);
                permHelper(num,ret,index+1);
                swap(num,index,i);
            }
        }
    }
    void swap(vector<int> &num,int i,int j) {
        int temp=num[i];
        num[i]=num[j];
        num[j]=temp;
    }
};