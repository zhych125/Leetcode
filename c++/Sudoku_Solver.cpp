class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        sudokuHelper(board,0,0);
    }
    
    bool sudokuHelper(vector<vector<char>> &board,int row, int col) {
        nextSpot(board,row,col);
        if(row==9) {
            return true;
        }
        for(int i=1;i<=9;i++) {
            if(checkValid(board,row,col,i+'0')) {
                board[row][col]=i+'0';
                if(sudokuHelper(board,row,col)) {
                    return true;
                }
                else board[row][col]='.';
            }
        }
        return false;
    }
    void nextSpot(vector<vector<char>> &board, int &row, int &col) {
        while(row<9&&board[row][col]!='.') {
            while(col<9&&board[row][col]!='.') {
                col++;
            }
            if(col==9) {
                col=0;
                row++;
            }
        }
    }
    bool checkValid(vector<vector<char>> &board, int row, int col, char num) {
        for(int i=0;i<9;i++) {
            if(board[row][i]==num||board[i][col]==num) {
                return false;
            }
        }
        for(int i=row/3*3;i<3+row/3*3;i++) {
            for(int j=col/3*3;j<3+col/3*3;j++) {
                if(board[i][j]==num) {
                    return false;
                }
            }
        }
        return true;
    } 
};