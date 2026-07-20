class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows, cols, subBoxes;
        int r,c,s;
        for(int i = 0;i<9;i++) {
            for(int j = 0;j<9;j++) {
            s = (i/3)*3+j/3;

                if(board[i][j]!= '.' 
                    && (rows[i].count(board[i][j])
                    || cols[j].count(board[i][j])
                    || subBoxes[s].count(board[i][j]))
                ) return false;
                else if (board[i][j]!= '.' ) {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    subBoxes[s].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
