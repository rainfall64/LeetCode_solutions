class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        // a ^ a = 0,  so every pair will result as 0
        // and a ^ 0 = 0, so only unique element will remain after xor'ing every element
        for (auto& y : nums)
            x ^= y;
        return x;
    }
};