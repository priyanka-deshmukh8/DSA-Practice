class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> q;
        vector<pair<int, int>> a;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    q.push_back(make_pair(i, j));
                } else if (grid[i][j] > 1) {
                    for (int k = 0; k < grid[i][j] - 1; ++k) {
                        a.push_back(make_pair(i, j));
                    }
                }
            }
        }
        
        return solve(0, 0, q, a);
    }
    
private:
    int solve(int ind, int bit, const vector<pair<int, int>>& q, const vector<pair<int, int>>& a) {
        if (ind == q.size()) {
            return 0;
        }
        
        int mn = INT_MAX;
        for (int i = 0; i < a.size(); ++i) {
            if (!(bit & (1 << i))) {
                int e = a[i].first;
                int f = a[i].second;
                int c = q[ind].first;
                int d = q[ind].second;
                int dist = abs(e - c) + abs(f - d);
                mn = min(mn, dist + solve(ind + 1, bit | (1 << i), q, a));
            }
        }
        
        return mn;
    }
};
