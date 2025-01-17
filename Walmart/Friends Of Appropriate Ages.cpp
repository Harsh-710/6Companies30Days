class Solution {
    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        unordered_map<int,int> count;

        for(int age: ages) count[age]++;

        for(auto &a: count){
            for(auto &b: count){
                if(request(a.first, b.first))
                    ans += a.second * (b.second - (a.first == b.first ? 1 : 0));
            }
        }

        return ans;
    }
};