class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int currentCol = mid % n;
            int currentRow = mid/n;
            if(matrix[currentRow][currentCol] == target) return true;
            if(matrix[currentRow][currentCol] > target) right = mid-1;
            else left = mid+1;
        }

        // index = col*currentRow + currentCol
        // currentCol = index % col
        // currentRow = (index - currentCol)/row
        
        return false;
    }
};