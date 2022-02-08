class Solution {
public:
    bool isSameAfterReversals(int num) {
        // if n == 0 then return true;
        // as we are only checking if the value is same or not we dont need to
        // calculate the whole reverse number only checking mse would give us the result 
        return (num == 0) | (num % 10 != 0); // both or ('|') operator or '||' would work
    }
};