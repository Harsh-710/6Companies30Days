class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, -1));

        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        string result;
        function<void(int, int)> construct = [&](int i, int j) {
            if (i == j) {
                result += 'A' + (i - 1);
                return;
            }
            result += '(';
            construct(i, bracket[i][j]);
            construct(bracket[i][j] + 1, j);
            result += ')';
        };

        construct(1, n - 1);
        return result;
    }
};
