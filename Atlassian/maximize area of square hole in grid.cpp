class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxwidth=0, maxlen=0;
        int prev = hBars[0];
        for(int i=1; i<hBars.size(); i++){
            int len = 0;
            while(i<hBars.size() and hBars[i] == hBars[i-1] + 1){
                len++; i++;
            }
            maxlen = max(maxlen, len);
        }
        maxlen += 2;

        prev = vBars[0];
        for(int i=1; i<vBars.size(); i++){
            int len = 0;
            while(i<vBars.size() and vBars[i] == vBars[i-1] + 1){
                len++; i++;
            }
            maxwidth = max(maxwidth, len);
        }
        maxwidth += 2;

        ans = min(maxlen, maxwidth);
        return ans*ans;
    }
};