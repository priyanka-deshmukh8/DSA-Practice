class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int mx = int(log2(1e10) + 1);
        int n = receiver.size();
        vector<vector<int>> first(mx, vector<int>(n));
        vector<vector<long long>> second(mx, vector<long long>(n));  // Use long long
        
        for (int i = 0; i < n; ++i) {
            first[0][i] = receiver[i];
            second[0][i] = receiver[i];
        }
        
        for (int i = 1; i < mx; ++i) {
            for (int j = 0; j < n; ++j) {
                first[i][j] = first[i - 1][first[i - 1][j]];
                second[i][j] = second[i - 1][j] + second[i - 1][first[i - 1][j]];
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long res = i;
            int curr = i;
            for (int j = 0; j < mx; ++j) {
                if (k & (1LL << j)) {
                    res += second[j][curr];
                    curr = first[j][curr];
                }
            }
            ans = max(ans, res);
        }
        
        return ans;
    }
};
