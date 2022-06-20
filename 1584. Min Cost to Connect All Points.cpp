class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> u;
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                u[i].push_back({dist, j});
                u[j].push_back({dist, i});
            }
        }
        int result = 0;
        set<int> visit;
        // prims algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (visit.size() < n)
        {
            int cost = pq.top().first, i = pq.top().second; pq.pop();
            if (visit.find(i) != visit.end())
            {
                continue;
            }
            result += cost;
            visit.insert(i);
            for (auto& x : u[i])
            {
                if (visit.find(x.second) == visit.end())
                {
                    pq.push({x.first, x.second});                    
                }
            }
        }
        return result;
    }
};