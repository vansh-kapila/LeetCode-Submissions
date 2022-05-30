class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {
            int l = 0, r = matrix.size() *matrix[0].size() - 1;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
                {
                    return 1;
                }
                else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            return 0;
        }
};