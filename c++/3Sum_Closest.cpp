class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sum=num[0]+num[1]+num[2];
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++) {
            if(i!=0&&num[i]==num[i-1]) continue;
            int begin=i+1;
            int end=num.size()-1;
            while(begin<end) {
                if(begin!=i+1&&num[begin]==num[begin-1]) {
                    begin++;
                    continue;
                }
                if(end!=num.size()-1&&num[end]==num[end+1]) {
                    end--;
                    continue;
                }
                int tempsum=num[i]+num[begin]+num[end];
                if(abs(tempsum-target)<abs(sum-target)) {
                    sum=tempsum;
                }
                if(tempsum==target) {
                    return target;
                }
                else if(tempsum<target) {
                    begin++;
                }
                else {
                    end--;
                }
            }
        }
        return sum;
    }
};