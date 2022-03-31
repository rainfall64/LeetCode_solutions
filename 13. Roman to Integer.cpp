class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int last_value = values[s[s.size() - 1]];
        int total = last_value;
        for (int i = s.size() - 2; i > -1; i--)
        {
            int curr_value = values[s[i]];
            if (curr_value < last_value)
                total -= curr_value;
            else
                total += curr_value;
            last_value = curr_value;
        }
        return total;
    }
};