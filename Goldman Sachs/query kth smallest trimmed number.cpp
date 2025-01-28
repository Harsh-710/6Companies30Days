class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n= nums.size(), m= queries.size(), slen= nums[0].size();
        vector<int> ans;

        for(int i=0; i<m; i++){
            int trim = queries[i][1], k = queries[i][0];
            vector<pair<string,int>> v;

            for(int j=0; j<n; j++){
                v.push_back({nums[j].substr(slen-trim), j});
            }
            sort(v.begin(), v.end());

            ans.push_back(v[k-1].second);
        }

        return ans;
    }
};