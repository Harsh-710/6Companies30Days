class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), ans=0;

        int i=0, j=0, cost=0;
        while(j<n){
            cost += abs(s[j] - t[j]);
            if(cost <= maxCost) ans = max(ans, j-i+1);
            else{
                while(cost > maxCost){
                    cost -= abs(s[i] - t[i]);
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};