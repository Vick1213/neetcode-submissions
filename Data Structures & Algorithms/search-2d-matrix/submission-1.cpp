class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = (int)matrix.size() - 1;

        // Step 1: find the row whose first element is <= target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        // high is now the last row whose first element is <= target
        if (high < 0) return false;

        return binarySearchOnRow(matrix[high], target);
    }

    bool binarySearchOnRow(vector<int>& row, int target) {
        int low = 0, high = (int)row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == target) return true;
            if (row[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};