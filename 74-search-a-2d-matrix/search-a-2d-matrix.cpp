class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {
            int n = matrix.size(), m = matrix[0].size();

           	// Binary search to find the correct row
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (matrix[mid][0] <= target && target <= matrix[mid][m - 1])
                {
                   	// Binary search in the found row
                    int l = 0, r = m - 1;
                    while (l <= r)
                    {
                        int midCol = (l + r) / 2;
                        if (matrix[mid][midCol] == target)
                        {
                            return true;
                        }
                        else if (matrix[mid][midCol] < target)
                        {
                            l = midCol + 1;
                        }
                        else
                        {
                            r = midCol - 1;
                        }
                    }
                    return false;	// If not found in the row
                }
                else if (matrix[mid][0] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return false;	// If the row was not found
        }
};