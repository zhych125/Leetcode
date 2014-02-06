class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()||matrix[0].empty()) {
            return;
        }
        int rowZero=matrix[0][0];
        int colZero=matrix[0][0];
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(i==0) {
                    if(matrix[i][j]==0) {
                        rowZero=0;
                    }
                }
                else if(j==0) {
                    if(matrix[i][j]==0) {
                        colZero=0;
                    }
                }
                else {
                    if(matrix[i][j]==0) {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<matrix.size();i++) {
            if(matrix[i][0]==0) {
                for(int j=1;j<matrix[0].size();j++) {
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<matrix[0].size();j++) {
            if(matrix[0][j]==0) {
                for(int i=1;i<matrix.size();i++) {
                    matrix[i][j]=0;
                }
            }
        }
        if(rowZero==0) {
            for(int j=0;j<matrix[0].size();j++) {
                matrix[0][j]=0;
            }
        }
        if(colZero==0) {
            for(int i=0;i<matrix.size();i++) {
                matrix[i][0]=0;
            }
        }
    }
};