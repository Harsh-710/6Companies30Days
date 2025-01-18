class Solution {
    int const mod = 1e9 +7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        long ans=1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums) pq.push(i);

        while(k>0){
            int num = pq.top(); pq.pop();
            pq.push(num+1);
            k--;
        }

        while(!pq.empty()){
            ans *= pq.top(); pq.pop();
            ans %= mod;
        }

        return ans;
    }
};