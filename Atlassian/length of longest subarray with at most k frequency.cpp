class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 1;
        unordered_map<int,int> m;

        int i=0, j=0;
        while(j<nums.size()){
            m[nums[j]]++;
            if(m[nums[j]] > k){
                while(m[nums[j]] > k and i<j){
                    m[nums[i]]--;
                    i++;
                }
            }else{
                ans = max(ans, j-i+1);
            }
            j++;
        }

        return ans;
    }
};