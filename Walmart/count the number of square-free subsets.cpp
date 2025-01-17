class Solution {
public:
    int mod=1e9+7;
    int dp[1000][1<<10];

    int pf(int a,int b){
        int ans=1;
        while(b){
            if(b&1){
                ans=(ans*1LL*a)%mod;
            }
            a=(a*1LL*a)%mod;
            b=b>>1;
        }
        return ans%mod;
    }
    int help(int mask,int idx,vector<int> &tmp){
        if(idx==tmp.size()){
            return mask!=0;
        }
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int notTake=help(mask,idx+1,tmp);
        int take=0;
        if((tmp[idx]&mask)==0){
            take=help(mask^tmp[idx],idx+1,tmp);
        }
        return dp[idx][mask]=(take+notTake)%mod;
    }

    int squareFreeSubsets(vector<int>& nums) {
        unordered_set<int> st={4,8,9,12,16,18,20,24,25,27,28};
        vector<int> factors={2,3,5,7,11,13,17,19,23,29};
        vector<int> tmp;
        int cnt0=0;

        for(auto x:nums){
            if(x==1){
                cnt0++;
                continue;
            }
            if(!st.count(x)){
                int t=0;
                for(int i=0;i<10;i++){
                    if(x%factors[i]==0){
                        t=t^(1<<i);
                    }
                }
                tmp.push_back(t);
            }
        }
        memset(dp,-1,sizeof dp);
        int ans=help(0,0,tmp);
        ans=((ans*1LL*pf(2,cnt0))%mod + 1LL*pf(2,cnt0)-1+mod)%mod;
        return ans;
    }
};