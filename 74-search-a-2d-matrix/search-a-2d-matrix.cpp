class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n-1;
        while (low <= high){
            int mid = (low + high)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                int l = 0, h = m-1;
                while (l <= h){
                    int midRow = (l+h)/2;
                    if (matrix[mid][midRow] == target){
                        return true;
                    }
                    else if ( target < matrix[mid][midRow]){
                        h = midRow - 1;
                    }
                    else{
                        l = midRow + 1;
                    }
                }
                return false;
            }
            else if (target < matrix[mid][0]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};