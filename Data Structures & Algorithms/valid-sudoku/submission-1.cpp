class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,bitset<10>> rows, cols, subBoxes;
        int r,c,s;
        for(int i = 0;i<9;i++) {
            for(int j = 0;j<9;j++) {
            s = (i/3)*3+j/3;

                if(board[i][j]!= '.' 
                    && (rows[i][board[i][j]-'0']
                    || cols[j][board[i][j]-'0']
                    || subBoxes[s][board[i][j]-'0'])
                ) return false;
                else if (board[i][j]!= '.' ) {
                    rows[i][board[i][j]-'0'] = 1;
                    cols[j][board[i][j]-'0'] = 1;
                    subBoxes[s][board[i][j]-'0'] = 1;
                }
            }
        }
        return true;
    }
};
