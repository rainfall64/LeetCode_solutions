class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // first calculate xor of only two unique numbers
        int x = 0;        
        for (auto y : nums)
            x ^= y;
        // now x contains only two unique numbers        
        
        // do and operation on x and -x
        // we are casting long to x before negetion to prevent overflow
        // we are finding right most set bit in x
        // by doing x and -x we get right most set bit 
        int diff = x & (-(long)x); 

        int z = 0;

        // we get two kinds of value
        // one which will give us one value another will give us other value
        // int k = 0
        for (auto y : nums)
        {
            if ((y & diff) != 0)
                z ^= y;
            /*
            // here we can also calculate second value using else statement
            else
                k ^= y;
            */
        }
        // return {z, k};
        // as we know that x is the xor of z and k
        // knowing one of them is enouf to find both
        return {z, x ^ z};
    }
};