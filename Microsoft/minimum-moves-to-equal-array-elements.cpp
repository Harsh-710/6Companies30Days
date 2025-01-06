class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];

        int ans = 0;
        for(int i: nums){
            ans += abs(median - i);
        }
        return ans;
    }
};