class Solution {
private:
    vector<vector<int>> res;
    vector<int> a;
    void f(vector<int> &nums, int n, int k, int index){
        if (n < 0) return;
        if (n == 0){
            if (a.size() == k) res.push_back(a);
            return;
        }
        for (int i = index; i < nums.size(); i++){
            a.push_back(nums[i]);
            f(nums, n - nums[i], k, i + 1);
            a.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        f(nums, n, k, 0);
        return res;
    }
};