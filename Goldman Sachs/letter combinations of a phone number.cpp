class Solution {
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void help(vector<string>& a, vector<string>& ans, string s = "", int i=0){
        if(i == a.size()){
            ans.push_back(s);
            return;
        }
        string first = a[i];
        for(char c : first){
            s.push_back(c);
            help(a, ans, s, i+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> a, ans;
        for(char c : digits){
            a.push_back(v[c - '0']);
        }
        help(a,ans);
        return ans;
    }
};