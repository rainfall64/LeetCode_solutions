class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n)
        {
            n &= (n - 1);
            result++;
        }
        return result;
    }
};

// one line recursion solution

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return 1 + (n > 0 ? hammingWeight(n & (n - 1)) : -1);
    }
};