class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> updated(m, vector<int>(n));

        queue<vector<int>> q;
        int fresh_oranges = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                updated[i][j] = grid[i][j];
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) fresh_oranges++;
            }
        }

        while(!q.empty()){
            queue<vector<int>> temp;
            bool flag = false;
            while(!q.empty()){
                int i = q.front()[0], j = q.front()[1];
                q.pop();
                if(i-1 >= 0 and updated[i-1][j] == 1){
                    updated[i-1][j] = 2;
                    temp.push({i-1, j});
                    flag = true;
                    fresh_oranges--;
                }
                if(i+1 < m and updated[i+1][j] == 1){
                    updated[i+1][j] = 2;
                    temp.push({i+1, j});
                    flag = true;
                    fresh_oranges--;
                }
                if(j-1 >= 0 and updated[i][j-1] == 1){
                    updated[i][j-1] = 2;
                    temp.push({i, j-1});
                    flag = true;
                    fresh_oranges--;
                }
                if(j+1 < n and updated[i][j+1] == 1){
                    updated[i][j+1] = 2;
                    temp.push({i, j+1});
                    flag = true;
                    fresh_oranges--;
                }

            }
            if(flag){
                ans++;
            }
            while(!temp.empty()){
                q.push(temp.front());
                temp.pop();
            }
        }

        return fresh_oranges > 0 ? -1 : ans;
    }
};