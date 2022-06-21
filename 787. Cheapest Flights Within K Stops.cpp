class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            vector<int> temp_prices = prices;
            for (auto& f : flights)
            {
                int s = f[0], d = f[1], p = f[2];
                if (prices[s] == INT_MAX)
                {
                    continue;
                }
                if (prices[s] + p < temp_prices[d])
                {
                    temp_prices[d] = prices[s] + p;
                }
            }            
            prices = temp_prices;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};