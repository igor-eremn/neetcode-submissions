class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        let s = new Set();
        for (let i=0; i<board.length; i++){
            for (let j=0; j<board[i].length; j++) {
                if (s.has(board[i][j])){
                    console.log(i, j, s);
                    return false;
                } else {
                    if (board[i][j] !== ".") s.add(board[i][j]);
                }
            }
            s.clear();
        }

        for (let i=0; i<board[0].length; i++) {
            for (let j=0; j<board.length; j++){
                if (s.has(board[j][i])){
                    console.log(j, i, s);
                    return false;
                } else {
                    if (board[j][i] !== ".") s.add(board[j][i]);
                }
            }
            s.clear();
        }

        for (let i=0; i<3; i++) {
            for (let j=0; j<3; j++){
                let temp = [];
                for (let k=0; k<3; k++){
                    if (board[(3 * i) + k][(3 * j) + 0] !== ".") temp.push(board[(3 * i) + k][(3 * j) + 0]);
                    if (board[(3 * i) + k][(3 * j) + 1] !== ".") temp.push(board[(3 * i) + k][(3 * j) + 1]);
                    if (board[(3 * i) + k][(3 * j) + 2] !== ".") temp.push(board[(3 * i) + k][(3 * j) + 2]);
                }

                console.log(temp);
                for (let k=0; k<temp.length; k++){
                    if (s.has(temp[k])){
                        return false;
                    } else {
                        s.add(temp[k]);
                    }
                }
                s.clear();
            }
        }

        return true;
    }
}
