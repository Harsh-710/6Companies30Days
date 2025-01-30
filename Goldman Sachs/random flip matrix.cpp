class Solution {
    int n,m,i=0,j=0;

public:

    Solution(int m, int n) {
        this->n=m; this->m=n;
    }

    vector<int> flip() {
        if(j>=m) {
            j=0; i++;
        }
        j++;
        if(i>=n) i=0;
        return {i,j-1};
    }

    void reset() {
        // no need
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */