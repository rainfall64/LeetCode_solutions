class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> u;
        for (const auto& x : s)
        {
            u[x]++;
        }
        for (const auto& y : t)
        {
            if (!u[y])
            {
                return false;
            }
            u[y]--;
            if (u[y] == 0)
            {
                u.erase(y);
            }
        }
        return u.empty();
    }
};