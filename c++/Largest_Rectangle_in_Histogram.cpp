class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()) {
            return 0;
        }
        height.push_back(0);
        stack<int> histack;
        int area=0;
        int i=0;
        while(i<height.size()) {
            if(histack.empty()||height[i]>height[histack.top()]) {
                histack.push(i);
                i++;
            }
            else {
                int tmp=histack.top();
                histack.pop();
                area=max(area,height[tmp]*(histack.empty()?i:i-histack.top()-1));
            }
        }
        return area;
    }
};