class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()||board[0].empty()) {
            return false;
        }
        if(word.empty()) {
            return true;
        }
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        int vertical[]={0,-1,0,1};
        int horizontal[]={-1,0,1,0};
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(existHelper(board,visited,word,vertical,horizontal,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    
    }
    bool existHelper(
            vector<vector<char>> &board,
            vector<vector<bool>> &visited,
            string &word,
            int (&vertical)[4],
            int (&horizontal)[4],
            int row,
            int col,
            int index
            ) {
        if(visited[row][col]) {
            return false;
        }
        if(word[index]==board[row][col]) {
            if(index+1==word.size()) {
                return true;
            }
            visited[row][col]=true;
            for(int i=0;i<4;i++) {
                int newRow=row+vertical[i];
                int newCol=col+horizontal[i];
                if(newRow>=0&&newRow<board.size()&&newCol>=0&&newCol<board[0].size()&&existHelper(board,visited,word,vertical,horizontal,newRow,newCol,index+1)) {
                    return true;
                }
            }
            visited[row][col]=false;
        }
        return false;
    }
};