// Algorithm
// result[0].size() != result[1].size();
// result[i].size() = result[i + 1].size() - 1;
// result[0][0]  = 1;
// i = 1 to n - 1
// j = 1 to i - 1
// if j == i result[i][j] = 1;
// else result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {{}};
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> result = {{1}};
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row = {1};
            for (int j = 1; j < i; j++)
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};