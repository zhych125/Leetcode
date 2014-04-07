class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty()) {
            return;
        }
        for(int i=num.size()-2;i>=0;i--) {
            if(num[i]<num[i+1]) {
                for(int j=num.size()-1;j>i;j--) {
                    if(num[j]>num[i]) {
                        swap(num,i,j);
                        break;
                    }
                }
                sort(num.begin()+i+1,num.end());
                return;
            }
        }
        return sort(num.begin(),num.end());
    }
    void swap(vector<int> &num,int i,int j) {
        num[i]=num[i]+num[j];
        num[j]=num[i]-num[j];
        num[i]=num[i]-num[j];
    }
};