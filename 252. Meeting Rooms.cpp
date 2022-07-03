class Solution {
private:
    struct Comparator{
        bool operator()(vector<int>& v1, vector<int>& v2)
        {
            if (v1[0] == v2[0])
            {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        }
    };
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
        {
            return true;
        }
        sort(intervals.begin(), intervals.end(), Comparator());
        int prevEnd = intervals[0][1], n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (prevEnd > intervals[i][0])
            {
                return false;
            }
            prevEnd = intervals[i][1];
        }
        return true;
    }
};