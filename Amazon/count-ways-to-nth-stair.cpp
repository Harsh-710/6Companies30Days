class Solution {
    vector<long long> comb(int n){
        vector<long long> ans(n+1, 1);
        for(int i=1; i<= n; i++){
            ans[i] = ans[n-i] = (long long)ans[i-1] * (n-i+1)/i;
        }
        return ans;
    }
public:
    int waysToReachStair(int k) {
        int ans[] = {2,4,4,3,2};
        if(k<5) return ans[k];

        int jump=0, b=1;
        for(jump=0; b<k; jump++, b = (1<<jump));

        int y = b-k;
        if(y > jump+1) return 0;
        return comb(jump+1)[y];
    }
};