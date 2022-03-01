class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        bool zero = false;
        for (auto x : nums)
        {
            if (x == 0)
                return 0;
            else if (x < 0)
                neg++;
        }        
        return neg % 2 ? -1 : 1;
    }
};