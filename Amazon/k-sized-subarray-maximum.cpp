class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
        int n = nums.size();
        vector<int> ans;
        map<int,int> m;
        int i=0, j=0;
        while(j < k){
            m[nums[j]]++;
            j++;
        }
        ans.push_back(m.rbegin()->first);
        while(j<n){
            m[nums[i++]]--;
            m[nums[j++]]++;
            while(!m.empty()){
                auto it = m.rbegin();
                if(it->second > 0){
                    ans.push_back(it->first);
                    break;
                }
                else m.erase(--m.end());
            }
        }
        return ans;
    }
};