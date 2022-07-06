class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> u;
        for (const auto& x : nums)
        {
            count += u[x]++;
        }
        return count;
    }
};