class Solution {
    int binarySearch(vector<vector<int>>& matrix, int target, int l, int r)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (matrix[m][0] <= target && matrix[m][matrix[m].size() - 1] >= target)
                return m;
            if (matrix[m][0] > target)
                r = m - 1;
            else
                l = m + 1;         
        }
        return -1;
    }
    int binarySearchCol(vector<int>& nums, int target, int l, int r)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if (n == 0 || m == 0)
            return false;
        int r = binarySearch(matrix, target, 0, n - 1);
        if (r == - 1)
            return false;
        return binarySearchCol(matrix[r], target, 0, m - 1) != -1;
    }
};