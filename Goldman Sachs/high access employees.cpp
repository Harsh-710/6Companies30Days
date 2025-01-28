class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& time) {
        int n = time.size();

        unordered_map<string, vector<int>>mp;
        for(auto it:time){
            string a = it[0];
            int t = stoi(it[1]);
            mp[a].push_back(t);
        }

        vector<string>ans;
        for(auto &[key, val]: mp){
            sort(val.begin(), val.end());
            int sz = val.size();

            bool flag = false;
            for(int i = 0; i+3<= sz;i++){
                if(val[i+2] < val[i] + 100) flag = true;
            }

            if(flag)ans.push_back(key);
        }

        return ans;
    }
};