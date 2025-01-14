class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<int> ans, indices;

        for(int i=0; i<nums.size(); i++){
            if(pq.size() == k){
                if(pq.top()[0] < nums[i]) pq.pop();
                else continue;
            }
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            auto v = pq.top(); pq.pop();
            indices.push_back(v[1]);
        }

        sort(indices.begin(), indices.end());

        for(int i: indices){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};