class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(char c : s) m[c]++;
        string ans;
        while(!m.empty()){
            int maxc = 0; char c;
            for(auto &it : m){
                if(it.second > maxc){
                    maxc = it.second;
                    c = it.first;
                }
            }
            while(m[c]--) ans.push_back(c);
            m.erase(c);
        }
        return ans;
    }
};