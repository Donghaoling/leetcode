class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while(i >= 0 && j < col) {
            if(target < matrix[i][j]) {
                --i;
            }
            else if(target > matrix[i][j]) {
                ++j;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
