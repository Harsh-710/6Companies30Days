class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
            int n = columnNumber % 26;
            ans.push_back(n+'A');
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};