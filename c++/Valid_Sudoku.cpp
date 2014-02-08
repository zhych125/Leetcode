class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++) {
            bool row[9]={false};
            bool col[9]={false};
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    if(row[board[i][j]-'1']) {
                        return false;
                    }
                    else row[board[i][j]-'1']=true;
                }
                if(board[j][i]!='.') {
                    if(col[board[j][i]-'1']) {
                        return false;
                    }
                    else col[board[j][i]-'1']=true;
                }
            }
        }
        for(int i=0;i<9;i=i+3) {
            for(int j=0;j<9;j=j+3) {
                bool block[9]={false};
                for(int k=i;k<i+3;k++) {
                    for(int l=j;l<j+3;l++) {
                        if(board[k][l]!='.') {
                            if(block[board[k][l]-'1']) {
                                return false;
                            }
                            else block[board[k][l]-'1']=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};