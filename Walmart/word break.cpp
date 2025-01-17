class Solution {
public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> v(n+1, false);
        v[n] = true;
        for(int i= n-1; i>=0; i--){
            for(string &t : wordDict){
                if(i + t.size() <= n && t == s.substr(i,t.size())){
                    v[i] = v[i + t.size()];
                }
                if(v[i]) break;
            }
        }
        return v[0];
    }
};