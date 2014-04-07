class Solution {
public:
    string simplifyPath(string path) {
        list<string> strStack;
        int i=0;
        while(i<path.size()) {
            if(path[i]=='/') {
                i++;
                string str;
                while(i<path.size()&&path[i]!='/') {
                    str.push_back(path[i]);
                    i++;
                }
                if(str=="..") {
                    if(strStack.size()) {
                        strStack.pop_back();
                    }
                } else if(str!="."&&str!="") {
                    strStack.push_back(str);
                }
            }
        }
        string ret="/";
        while(strStack.size()) {
            ret=ret+strStack.front();
            strStack.pop_front();
            if(strStack.size()) {
                ret+="/";
            }
        }
        return ret;
    }
};