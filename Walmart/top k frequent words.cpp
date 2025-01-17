class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string &s: words){
            freq[s]++;
        }

        vector<set<string>> v(501);
        for(auto &it: freq){
            v[it.second].insert(it.first);
        }

        vector<string> ans;
        for(int i=500; i>=0; i--){
            if(!v[i].empty()){
                for(auto str: v[i]){
                    ans.push_back(str);
                    if(ans.size() == k) return ans;
                }
                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};