class Solution {
public:
    int dp[1001];
    int prev[1001];

    int numberOfWays(int startPos, int endPos, int k) {
        for (int s = 1; s <= k; s++) {
            for (int d = 0; d < s; d++) {
                dp[d] = (prev[abs(d-1)] + prev[d+1]) % ((int)1e9 + 7);
            }
            dp[s] = 1;
            memcpy(prev, dp, sizeof(dp));
        }
        return dp[abs(startPos - endPos)];
    }
};