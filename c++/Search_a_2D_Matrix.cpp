class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size()==0||matrix[0].size()==0) {
            return false;
        } 
        int begin=0;
        int end=matrix.size()-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(matrix[mid][0]==target) {
                return true;
            }
            else if(matrix[mid][0]>target) {
                end=mid-1;
            }
            else {
                begin=mid+1;
            }
        }
        if(end<0) {
            return false;
        }
        int row=end;
        begin=0;
        end=matrix[0].size()-1;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(matrix[row][mid]==target) {
                return true;
            }
            else if(matrix[row][mid]>target) {
                end=mid-1;
            }
            else {
                begin=mid+1;
            }
        }
        return false;
    }
};