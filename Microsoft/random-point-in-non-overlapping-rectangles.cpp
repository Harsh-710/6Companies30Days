class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        cumulativeArea.push_back(0);
        for (const auto& rect : rects) {
            int width = rect[2] - rect[0] + 1;
            int height = rect[3] - rect[1] + 1;
            int area = width * height;
            cumulativeArea.push_back(cumulativeArea.back() + area);
        }
        srand(time(nullptr));
    }
    
    vector<int> pick() {
        int totalArea = cumulativeArea.back();
        int randomArea = rand() % totalArea;

        int rectIndex = upper_bound(cumulativeArea.begin(), cumulativeArea.end(), randomArea) - cumulativeArea.begin() - 1;

        const auto& rect = rects[rectIndex];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];

        return {x, y};
    }

private:
    vector<vector<int>> rects;
    vector<int> cumulativeArea;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */