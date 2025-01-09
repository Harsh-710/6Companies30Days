class Solution {
    vector<char> order = { '!','#','$','%','&','*','?','@','^' };
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        map<char,int> m;
        for(int i=0; i<n; i++){
            m[nuts[i]]++;
        }
        
        int idx=0;
        for(int i=0; i<=9; i++){
            if(m[order[i]]){
                nuts[idx] = order[i];
                bolts[idx++] = order[i];
            }
        }
    }
};
