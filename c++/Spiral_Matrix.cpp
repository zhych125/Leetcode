class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty()||matrix[0].empty()) {
            return ret;
        }
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        while(left<right&&top<bottom) {
            for(int j=left;j<right;j++) {
                ret.push_back(matrix[top][j]);
            }
            for(int i=top;i<bottom;i++) {
                ret.push_back(matrix[i][right]);
            }
            for(int j=right;j>left;j--) {
                ret.push_back(matrix[bottom][j]);
            }
            for(int i=bottom;i>top;i--) {
                ret.push_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if(left==right&&top<=bottom) {
            for(int i=top;i<=bottom;i++) {
                ret.push_back(matrix[i][left]);
            }
        }
        if(top==bottom&&left<right) {
            for(int j=left;j<=right;j++) {
                ret.push_back(matrix[top][j]);
            }
        }
        return ret;
    }
};