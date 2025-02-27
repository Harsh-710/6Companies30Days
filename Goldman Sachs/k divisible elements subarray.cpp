class Solution {
public:  
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>ans;

        for(int i=0;i<nums.size();i++)
        { 
            vector<int>arr;
            int count=0;
            for(int j=i;j<nums.size();j++){
                arr.push_back(nums[j]);
                
                if(nums[j]%p==0)
                count++;
                if(count>k)
                break;
                ans.insert(arr);
            }
        }

        return ans.size();
    }
};