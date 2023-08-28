class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
       if (accumulate(nums.begin(), nums.end(), 0LL) < target) {  // Use 0LL for long long literal
            return -1;
        }
        
        unordered_map<int, int> c;
        for (int num : nums) {
            c[num]++;
        }
        
        int j = 32;
        int cnt = 0;
        for (int i = 0; i < 31; ++i) {
            if (target & (1LL << i)) {  // Use 1LL for long long literal
                if (c[1 << i]) {
                    c[1 << i]--;
                } else {
                    j = min(j, i);
                }
            }
            if (c[1 << i] && j < i) {
                c[1 << i]--;
                cnt += i - j;
                j = 32;
            }
            c[1 << (i + 1)] += (c[1 << i] / 2);
        }
        return cnt;
    }
};