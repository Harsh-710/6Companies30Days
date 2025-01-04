
bool comp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
    int lb(vector<vector<int>>& v, int key){
        int hi = v.size(), lo = 0, mid;
        while(lo < hi){
            mid = (hi + lo)>>1;
            if(v[mid][1] < key) lo = mid +1;
            else hi = mid;
        }
        return lo;
    }

public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        vector<vector<int>> v;
        sort(env.begin(), env.end(), comp);
        v.push_back(env[0]);
        for(int i=1; i<n; i++){
            if(env[i][1] > v.back()[1]){
                v.push_back(env[i]);
                continue;
            }
            int idx = lb(v, env[i][1]);
            if(idx == v.size()) continue;
            v[idx] = env[i];
        }
        return v.size();
    }
};