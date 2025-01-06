class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int maxMask = 1 << n;
        vector<int> dp(maxMask, 0);

        for (int mask = 0; mask < maxMask; ++mask) {
            string subseq;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }
            if (isPalindrome(subseq)) {
                dp[mask] = subseq.size();
            }
        }

        int maxProduct = 0;

        for (int mask1 = 0; mask1 < maxMask; ++mask1) {
            for (int mask2 = mask1 + 1; mask2 < maxMask; ++mask2) {
                if ((mask1 & mask2) == 0) {
                    maxProduct = max(maxProduct, dp[mask1] * dp[mask2]);
                }
            }
        }

        return maxProduct;
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
