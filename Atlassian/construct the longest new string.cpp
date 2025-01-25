class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;

        if(x == 0 or y == 0){
            return 2* (1 + z);
        }
        
        ans += min(x,y) * 2;
        if(x != y) ans++;
        ans += z;
        return ans*2;
    }
};