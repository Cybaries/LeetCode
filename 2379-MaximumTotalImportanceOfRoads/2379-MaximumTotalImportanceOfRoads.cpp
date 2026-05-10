// Last updated: 11/05/2026, 01:30:37
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long roads_touching[n];
        for (int i = 0; i < n; ++i)
            roads_touching[i] = 0;
        for (const auto& road : roads) {
            ++roads_touching[road[0]];
            ++roads_touching[road[1]];
        }
        sort(roads_touching, roads_touching+n);
        long long result = 0;
        for (long long i = 0; i < n; ++i) {
            result += (i+1)*roads_touching[i];
        }
        return result;    
    }
};