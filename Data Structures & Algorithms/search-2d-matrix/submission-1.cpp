class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lr = 0;
        int rr = matrix.size() - 1;
        int nr = INT_MAX;

        while (lr <= rr) {
            int mr = lr + (rr - lr) / 2;
            int s = matrix[mr][0];
            int e = matrix[mr][matrix[mr].size() - 1];

            if (target == s || target == e) {
                return true;
            } else if (s < target && e > target) {
                nr = mr;
                break;
            } else if (s > target) {
                rr = mr - 1;
            } else if (e < target) {
                lr = mr + 1;
            }
            
        }

        if (nr == INT_MAX) return false;

        int l = 0;
        int r = matrix[nr].size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (matrix[nr][m] == target) {
                return true;
            } else if (matrix[nr][m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};
