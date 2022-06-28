class Solution {
private:
    int subsetSum(vector<int>& nums, int target)
    {
        int dp[target + 1];
        dp[0] = 1;
        for (int i = 1; i < target + 1; i++)
        {
            dp[i] = 0;
        }
        for (const auto& x : nums)
        {
            for (int i = target; i >= x; i--)
            {
                dp[i] += dp[i - x];
            }            
        }
        return dp[target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 1)
        {
            return nums[0] == target || -nums[0] == target;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < target || (target + sum) & 1 ? 0 : subsetSum(nums, (target + sum) >> 1); // (target + sum) / 2 will also work
    }
};