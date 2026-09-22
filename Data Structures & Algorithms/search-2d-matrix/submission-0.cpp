class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        int top = 0;
        int bottom = m;

        int row = -1;

        bool rowExists = false;
        while(top <= bottom) {
            int middle = top + (bottom - top) / 2;
            if(isWithin(target, matrix[middle][0], matrix[middle][n])) {
                row = middle;
                break;
            }
            else if(target > matrix[middle][n]) {
                top = middle + 1;
            }
            else if(target < matrix[middle][0]) {
                bottom = middle - 1;
            }
        }

        if(row == -1) return false;

        int left = 0; 
        int right = n;
        
        while(right >= left) {
            int middle = left + (right - left) / 2;
            int currVal = matrix[row][middle];

            if(currVal == target) return true;
            else if(target > currVal) {
                left = middle + 1;
            }
            else if(target < currVal) {
                right = middle - 1;
            }
        }
        return false;
    }

    bool isWithin(int target, int low, int high) {
        if(target >= low && target <= high) {
            return true;
        }
        return false;
    }
};
