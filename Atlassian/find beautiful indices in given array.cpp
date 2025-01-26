class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(a.size() > s.size() or b.size() > s.size()) return {};
        vector<int> iarray, jarray, ans;

        for(int i=0; i<= s.size()-a.size(); i++){
            if(s.substr(i, a.size()) == a) iarray.push_back(i);
        }
        for(int i=0; i<= s.size()-b.size(); i++){
            if(s.substr(i, b.size()) == b) jarray.push_back(i);
        }

        int i=0, j=0;
        while(i< iarray.size() and j< jarray.size()){
            int diff = abs(iarray[i] - jarray[j]);
            if(diff <= k){
                ans.push_back(iarray[i]);
                i++;
                continue;
            }
            if(iarray[i] < jarray[j]) i++;
            else j++;
        }

        return ans;
    }
};