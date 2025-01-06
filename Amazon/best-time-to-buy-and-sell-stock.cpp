class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<vector<int>>> v(n+1, vector<vector<int>>(2, vector<int>(k+1)));
        for(int i=n-1; i>=0; i--){
            for(int tr = 1; tr <= k; tr++){
                v[i][0][tr] = max(v[i+1][0][tr], v[i+1][1][tr-1] + prices[i]);
                v[i][1][tr] = max(v[i+1][1][tr], v[i+1][0][tr] - prices[i]);
            }
        }
        int ans = 0;
        for(int i=0; i<=k; i++){
            ans = max(ans, v[0][1][i]);
        }
        return ans;
    }
};