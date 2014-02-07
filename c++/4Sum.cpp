class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if(num.size()<4) {
            return ret;
        }
        sort(num.begin(),num.end());
        int len=num.size();
        for(int i=0;i<len-3;i++) {
            if(i!=0&&num[i]==num[i-1]) {
                continue;
            }
            for(int j=i+1;j<len-2;j++) {
                if(j!=i+1&&num[j]==num[j-1]) {
                    continue;
                }
                int begin=j+1;
                int end=len-1;
                while(begin<end) {
                    if(begin!=j+1&&num[begin]==num[begin-1]){
                        begin++;
                        continue;
                    }
                    if(end!=len-1&&num[end]==num[end+1]) {
                        end--;
                        continue;
                    }
                    int sum=num[i]+num[j]+num[begin]+num[end];
                    if(sum==target) {
                        vector<int> line={num[i],num[j],num[begin],num[end]};
                        ret.push_back(line);
                        begin++;
                        end--;
                    }
                    else if(sum<target) {
                        begin++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        return ret;
    }
};