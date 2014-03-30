class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.empty()) {
            return 0;
        }
        int begin = 0;
        int end = height.size()-1;
        int maxArea = 0;
        while(begin<end) {
            int area = min(height[begin],height[end])*(end - begin);
            maxArea = max(area,maxArea);
            if(height[begin]<height[end]) {
                int hstart = height[begin];
                while(begin<end&&height[begin]<=hstart) {
                    begin++;
                }
            }
            else {
                int hend = height[end];
                while(begin<end&&height[end]<=hend) {
                    end--;
                }
            }
        }
        return maxArea;
    }
};