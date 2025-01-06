class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int x = 1;
        while(x <= n) q.push(x++);
        while(q.size() > 1){
            x = k - 1;
            while(x--){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};