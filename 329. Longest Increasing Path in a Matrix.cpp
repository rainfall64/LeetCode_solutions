class Solution {
    // Store the longest path in from each position in a dp matrix same size to the input matrix
    // and use them accordingly so we don't have to recalculate them again each time.    

    int dfs(vector<vector<int>>& matrix, int ROWS, int COLS, int r, int c, vector<vector<int>>& dp, int prevVal)
    {
        if (r < 0 || r == ROWS or c < 0 || c < 0 || c == COLS || matrix[r][c] <= prevVal)
            return 0;
        if (dp[r][c] != 0)
            return dp[r][c];
        int result = 1; // shortest path should be 1
        // Look at four direction from the postioon we are at, and send current matrix val val PrevVa;
        // shortest path should be 1 not 0 so add 1 with each dfs call
        result = max(result, 1 + dfs(matrix, ROWS, COLS, r + 1, c, dp, matrix[r][c]));
        result = max(result, 1 + dfs(matrix, ROWS, COLS, r - 1, c, dp, matrix[r][c]));
        result = max(result, 1 + dfs(matrix, ROWS, COLS, r, c + 1, dp, matrix[r][c]));
        result = max(result, 1 + dfs(matrix, ROWS, COLS, r, c - 1, dp, matrix[r][c]));
        dp[r][c] = result;
        return result;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        // dp to store each cell values
        // unordered_map can be used while making a pairing_funtion from each r and c values
        // https://en.wikipedia.org/wiki/Pairing_function
        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));
        int result = INT_MIN;
        // calculate each cell longest increasing path
        // also we can get the max(dp) from same loop
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
                result = max(result, dfs(matrix, ROWS, COLS, r, c, dp, -1));
        }
        return result;
    }
};