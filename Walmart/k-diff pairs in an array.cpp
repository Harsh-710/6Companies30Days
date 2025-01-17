class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), i=0, j=1;
        sort(nums.begin(), nums.end());
        set<int> s;

        while(j<n){
            int diff = nums[j] - nums[i];
            if(diff == k) s.insert(nums[i] + nums[j]);
            if(diff < k) j++;
            else i++;
            if(i==j) j++;
        }

        return s.size();
    }
};