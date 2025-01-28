class Solution {
    long long lcm(long long a,long long b){
        return (a * b)/(__gcd(a,b));
    }
public:
    bool ispossible(int mid,int d1,int d2,int u1,int u2){
        int c1 = (int)mid/d1;
        int c2 = (int)mid/d2;
        int temp = (int)mid/lcm(d1,d2);
        u1 -= (c2 - temp);
        u2 -= (c1 - temp);
        int t1 = mid - (c1 + c2 - temp);
        if(u1 < 0)u1 = 0;
        if(u2 < 0)u2 = 0;
        if(t1 >= u1 + u2)return true;
        return false;
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long l = 1,r = 1e12;
        int ans = 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(ispossible(mid,d1,d2,u1,u2)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};