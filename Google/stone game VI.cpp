class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int alice=0, bob=0, n= bobValues.size();
        priority_queue<pair<int,int>> pq;

        for(int i=0; i<n; i++){
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        while(!pq.empty()){
            alice += aliceValues[pq.top().second]; pq.pop();
            if(pq.empty()) break;
            bob += bobValues[pq.top().second]; pq.pop();
        }

        if(alice == bob) return 0;
        if(alice > bob) return 1;
        return -1;
    }
};