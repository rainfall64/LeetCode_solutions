class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, set<pair<int, int>>> u;
        set<int> visit;
        for (const auto& x : times)
        {
            u[x[0]].insert({x[1], x[2]}); // [u] = {v, w}
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int t = 0;
        while (!pq.empty())
        {
            int w1 = pq.top().first, n1 = pq.top().second; pq.pop();
            if (visit.find(n1) != visit.end())
            {
                continue;
            }
            visit.insert(n1);
            t = max(t, w1);
            for (auto& x : u[n1])
            {
                int n2 = x.first, w2 = x.second;
                if (visit.find(n2) == visit.end())
                {
                    pq.push({w1 + w2, n2});                    
                }
            }
        }
        return visit.size() == n ? t : -1;
    }
};