class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        int k = 0;

        for (int i = 1; i <= s.length(); i++) {
            vector<string> innerAns;
            string prefix = s.substr(k, i - k);

            for (int j = 0; j < n; j++) {
                size_t idx = contact[j].find(prefix);
                if (idx != string::npos) {
                    if (find(innerAns.begin(), innerAns.end(), contact[j]) == innerAns.end()) {
                        innerAns.push_back(contact[j]);
                    }
                }
            }
            if (innerAns.empty()) {
                innerAns.push_back("0");
            } else {
                sort(innerAns.begin(), innerAns.end());
            }
            ans.push_back(innerAns);
        }

        return ans;
    }
};