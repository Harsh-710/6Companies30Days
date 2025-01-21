class Solution {
public:
    void dfs_Utils( int i , int j , vector<vector<int>>& grid , vector<vector<bool>>& visited ){
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(visited[i][j] || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true; 
        dfs_Utils( i+1  , j ,  grid , visited );
        dfs_Utils( i  , j+1 ,  grid , visited );
        dfs_Utils( i-1  , j ,  grid , visited );
        dfs_Utils( i  , j-1 ,  grid , visited );
    }
    void dfs( vector<vector<int>>& grid ,  int & islands ){
        vector<vector<bool>>visited(grid.size() , vector<bool>(grid[0].size() , false));
        islands = 0;
        for( int i = 0 ;  i <  grid.size() ; i++){
            for( int j =0 ; j < grid[0].size() ; j++){
                if( grid[i][j] == 1 && !visited[i][j]){
                    dfs_Utils( i , j , grid , visited);
                    islands++;
                }
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        int islands;
        dfs( grid , islands);

        if( islands != 1){
            return 0;
        }

        for( int i =0; i < grid.size() ; i++){
            for( int j =0 ; j < grid[0].size() ; j++){
                if( grid[i][j] == 1 ){
                    grid[i][j] = 0;
                    dfs(grid , islands);
                    if( islands != 1){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};