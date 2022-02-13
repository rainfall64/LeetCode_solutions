class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26, 0);
        for (auto& c : magazine)
            hash[c - 'a']++;
        for (auto& x : ransomNote)
        {
            if (hash[x - 'a'] == 0)
                return false;
            else
                hash[x - 'a']--;
        }
        return true;
    }
};