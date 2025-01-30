class Solution {
    int M = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long dp[n+2];
        if(n==1)return 1;
        dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++){
            long long sharable = 0;
            if(i-delay>=0){
                sharable = (sharable + dp[i-delay])%M;
            }
            if(i-forget>=0){
                sharable = (sharable+M -dp[i-forget])%M;
            }
            dp[i] = (dp[i-1] +0LL+ (sharable))%M ; 
        }

        return (dp[n]-dp[n-forget]+M)%M;
    }
};