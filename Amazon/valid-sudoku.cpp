class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int n = 9;
        for(int i=0; i<n; i++){
            map<char,int> m;
            for(int j=0; j<n; j++){
                if(a[i][j] == '.') continue;
                if(m[a[i][j]]) return false;
                m[a[i][j]]++;
            }
        }
        for(int i=0; i<n; i++){
            map<char,int> m;
            for(int j=0; j<n; j++){
                if(a[j][i] == '.') continue;
                if(m[a[j][i]]) return false;
                m[a[j][i]]++;
            }
        }
        map<pair<int,int>, map<char,int>> mp;
        for(int i=0; i<n; i++){
            map<char,int> m;
            for(int j=0; j<n; j++){
                if(a[i][j] == '.') continue;
                pair<int,int> p = {i/3, j/3};
                if(mp[p][a[i][j]]) return false;
                mp[p][a[i][j]]++;
            }
        }
        return true;
    }
};