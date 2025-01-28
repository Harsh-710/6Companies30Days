class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater.back().size();
        using point = array<int,2>;
        deque<point> Q;
        vector<vector<int>> H(rows, vector<int>(cols, -1));
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(isWater[i][j])
                {
                    H[i][j] = 0;
                    Q.push_back({i, j});
                }
            }
        }

        static vector<point> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!Q.empty())
        {
            auto p = Q.front();
            Q.pop_front();
            int val = H[p[0]][p[1]];
            for(auto d : dirs)
            {
                auto nx = p[0] + d[0];
                auto ny = p[1] + d[1];
                if(nx >=0 && ny >=0 && nx < rows && ny < cols && H[nx][ny] == -1)
                {
                    H[nx][ny] = val + 1;
                    Q.push_back({nx,ny});
                }
            }            
        }

        return H;
    }
};