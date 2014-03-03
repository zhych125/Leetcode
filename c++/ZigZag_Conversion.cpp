class Solution {
public:
    string convert(string s, int nRows) {
        string ret;
        if(s.empty()) {
            return ret;
        }
        if(nRows==1) {
            return s;
        }
        vector<string> list(nRows,"");
        int n=0;
        bool flag=true;
        int i=0;
        for(int i=0;i<s.size();i++) {
            if(flag) {
                list[n].push_back(s[i]);
                n++;
                if(n==nRows) {
                    flag=false;
                    n-=2;
                }
            }
            else {
                list[n].push_back(s[i]);
                n--;
                if(n==-1) {
                    flag=true;
                    n+=2;
                }
            }
        }
        for(int i=0;i<list.size();i++) {
            ret+=list[i];
        }
        return ret;
    }
};