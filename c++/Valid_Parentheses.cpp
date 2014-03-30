class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) {
            return false;
        }
        stack<char> paStack;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='('||s[i]=='{'||s[i]=='[') {
                paStack.push(i);
            }
            else if(paStack.empty()) {
                return false;
            } else {
                if(s[paStack.top()]=='('&&s[i]==')') {
                    paStack.pop();
                    continue;
                }
                else if(s[paStack.top()]=='{'&&s[i]=='}') {
                    paStack.pop();
                    continue;
                }
                else if(s[paStack.top()]=='['&&s[i]==']') {
                    paStack.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return paStack.empty();
    }
};