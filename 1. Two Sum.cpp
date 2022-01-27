class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> u;
        for(int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            if(u.find(x) == u.end()) // check if the target does not exists in the hash
                u[nums[i]] = i; // if x does not exist store the index of nums[i]
            else // if the target (nums[i] + x) exists return the x index and current element index
                return {u[x], i};
        }
        return {-1, -1}; // default case
    }
};