class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,0));
        if(n==0) {
            return matrix;
        }
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int k=1;
        while(left<right&&top<bottom) {
            for(int j=left;j<right;j++) {
                matrix[top][j]=k++;
            }
            for(int i=top;i<bottom;i++) {
                matrix[i][right] = k++;
            }
            for(int j = right;j>left;j--) {
                matrix[bottom][j] = k++;
            }
            for(int i = bottom;i>top;i--) {
                matrix[i][left] = k++;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if(left==right&&top==bottom) {
            matrix[top][left] = k;
        }
        return matrix;
    }
};