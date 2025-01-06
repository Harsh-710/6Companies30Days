class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int oddCount = 0, result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (count.find(oddCount - k) != count.end()) {
                result += count[oddCount - k];
            }
            count[oddCount]++;
        }

        return result;
    }
};
