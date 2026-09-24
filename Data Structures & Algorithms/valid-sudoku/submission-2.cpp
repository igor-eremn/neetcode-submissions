class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            unordered_set<char> s{};
            for (int k=0; k<board[i].size(); k++){
                if (board[i][k] != '.' && s.contains(board[i][k])){
                    return false;
                } else if (board[i][k] != '.'){
                    s.insert(board[i][k]);
                }
            }
            s.clear();
        }

        for (int i=0; i<board[0].size(); i++) {
            unordered_set<char> s{};
            for (int k=0; k<board[i].size(); k++) {
                if (board[k][i] != '.' && s.contains(board[k][i])){
                    return false;
                } else if (board[k][i] != '.'){
                    s.insert(board[k][i]);
                }
            }   
            s.clear();
        }

        for (int i=0; i<3; i++) {
            for (int k=0; k<3; k++){
                unordered_set<char> s{};
                for (int r=3 * i; r<(3 * i) + 3; r++){
                    for (int c=3 * k; c<(3 * k) + 3; c++){
                        if (board[r][c] != '.' && s.contains(board[r][c])){
                            return false;
                        } else if (board[r][c] != '.'){
                            s.insert(board[r][c]);
                        }
                    }
                }
                s.clear();
            }
        }

        return true;
    }
};
