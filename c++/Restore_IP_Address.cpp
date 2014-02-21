class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string addr;
        restoreHelper(s,ret,addr,0,0);
        return ret;
        
    }
    
    void restoreHelper(string &s, vector<string> &ret,string &addr, int pos,int digit) {
        if(s.size()-digit>(4-pos)*3) {
            return;
        }
        if(s.size()-digit<(4-pos)) {
            return;
        }
        if(pos==4) {
            if(digit==s.size())
                ret.push_back(addr);
            return;
        }
        if(pos!=0) {
            addr.push_back('.');
        }
        int number=0;
        for(int i=digit;i<digit+3&&i<s.size();i++) {
            number=number*10+s[i]-'0';
            if(number<=255) {
                addr.push_back(s[i]);
                restoreHelper(s,ret,addr,pos+1,i+1);
            }
            if(number==0) {
                break;
            }
        }
        while(addr.size()&&addr.back()!='.') {
            addr.pop_back();
        }
        if(addr.size()) {
            addr.pop_back();
        }
        
    }
};