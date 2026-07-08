class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> s{};

        // check rows
        for (int r=0; r<board.size(); r++){
            for (int c=0; c<board[0].size(); c++){
                if (board[r][c] != '.'){
                    if (!s.insert(board[r][c]).second) return false;
                }
            }
            s.clear();
        }

        // check columns
        for (int c=0; c<board[0].size(); c++){
            for (int r=0; r<board.size(); r++){
                if (board[r][c] != '.'){
                    if (!s.insert(board[r][c]).second) return false;
                }
            }
            s.clear();
        }

        // check squares
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                for (int r=i*3; r<i*3+3; r++){
                    for (int c=j*3; c<j*3 + 3; c++){
                        if (board[r][c] != '.'){
                            if (!s.insert(board[r][c]).second) return false;
                        }
                    }
                }
                s.clear();
            }
        }

        return true;
    }
};
