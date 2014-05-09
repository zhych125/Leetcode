class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) {
            return 0;
        }
        stack<int> pStack;
        int maxLength=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                pStack.push(i);
            } else {
                if(pStack.size()&&s[pStack.top()]=='(') {
                    pStack.pop();
                    if(pStack.empty()) {
                        maxLength=max(maxLength,i+1);
                    } else  {
                        maxLength=max(maxLength,i-pStack.top());
                    }
                } else  {
                    pStack.push(i);
                }
            }
        }
        return maxLength;
    }
};