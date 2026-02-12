class Solution {
public:



    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> sumRow(m, vector<int>(n, 0));
        vector<vector<int>> sumCol(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (j == 0) sumRow[i][j] = grid[i][j];
                else sumRow[i][j] = sumRow[i][j - 1] + grid[i][j];

                if (i == 0) sumCol[i][j] = grid[i][j];
                else sumCol[i][j] = sumCol[i - 1][j] + grid[i][j];
            }
        }

        for (int k = min(m, n); k > 1; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (check(grid, sumRow, sumCol, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }

    bool check(vector<vector<int>>& grid, vector<vector<int>>& sumRow, vector<vector<int>>& sumCol, int i, int j, int k) {
        int target = sumRow[i][j + k - 1] - (j == 0 ? 0 : sumRow[i][j - 1]);

        for (int x = 0; x < k; x++) {
 
            int sRow = sumRow[i + x][j + k - 1] - (j == 0 ? 0 : sumRow[i + x][j - 1]);
            if (sRow != target) return false;
   
            int sCol = sumCol[i + k - 1][j + x] - (i == 0 ? 0 : sumCol[i - 1][j + x]);
            if (sCol != target) return false;
        }
        
        int d1 = 0, d2 = 0;
        for (int x = 0; x < k; x++) {
            d1 += grid[i + x][j + x]; 
            d2 += grid[i + x][j + k - 1 - x];
        }

        return d1 == target && d2 == target;
    }



};