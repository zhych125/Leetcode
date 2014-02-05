class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty())
        {
            return 0;
        }
        stack<int> storage;
        for(int i=0;i<tokens.size();i++)
        {
            if (tokens[i]=="+")
            {
                int a=storage.top();
                storage.pop();
                storage.top()=a+storage.top();
            }
            else if(tokens[i]=="-")
            {   
                int a=storage.top();
                storage.pop();
                storage.top()=storage.top()-a;
            }
            else if(tokens[i]=="*")
            {
                int a=storage.top();
                storage.pop();
                storage.top()=storage.top()*a;
            }
            else if(tokens[i]=="/")
            {
                int a=storage.top();
                storage.pop();
                storage.top()=storage.top()/a;
            }
            else
            {
                storage.push(atoi(tokens[i].c_str()));
            }
        }
        return storage.top();
    }
};