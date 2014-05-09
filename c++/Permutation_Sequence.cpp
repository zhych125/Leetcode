class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1) {
            return "1";
        }
        int factorial=1;
        int num[9];
        for(int i=1;i<=n;i++) {
            factorial*=i;
            num[i-1]=i;
        }
        factorial/=n;
        string ret;
        k=k-1;
        int m=n-1;
        while(k!=0) {
            int index=k/factorial;
            k=k%factorial;
            factorial=factorial/m;
            
            ret.push_back(num[index]+'0');
            for(int i=index+1;i<=m;i++) {
                num[i-1]=num[i];
            }
            m=m-1;
        }
        int i=0;
        while(ret.size()!=n) {
            ret.push_back(num[i]+'0');
            i++;
        }
        return ret;
    }
};