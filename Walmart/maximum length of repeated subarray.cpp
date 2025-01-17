class RollingHash {
    public:
    vector<long long int> power;
    vector<long long int> hash;
    RollingHash(vector<int> v, int base=31, int mod=1e9+7) {
        power.resize(v.size() + 2, 1);
        hash.resize(v.size() + 2, 0);
    
        for(int i=0; i<v.size();i++) {
            power[i+1] = (power[i] * base) % mod;
            hash[i+1] = (hash[i] * base + v[i]) % mod;
        }
    }

    int getHash(int l, int r, int mod=1e9+7) {
        long long int value = hash[r+1] - (hash[l] * power[r-l+1]) % mod;
        value = value + mod;
        return value % mod;
    }
};

class Solution {
public:
    int comp(vector<int> &nums1, vector<int> &nums2, int i, int j, int m) {
        if (i + m > nums1.size() || j + m > nums2.size()) return false;

        int t = 0; 
        while(t < m) {
            if (nums1[t+i] != nums2[j+t]) return false;
            t++;
        }

        return true;
    } 
    bool solve(vector<int>& nums1, vector<int>& nums2, int m, RollingHash & r1, RollingHash & r2) {
        int i = 0;
        int p = m; 
        unordered_map<int, vector<int>> s;
        while(m <= nums1.size()) {
            int hash1 = r1.getHash(i, m-1);
            s[hash1].push_back(i);
            i++;
            m++;
        }

        i = 0;
        m = p;

        while(m <= nums2.size()) {
            int hash1 = r2.getHash(i, m-1);
            if (s.find(hash1) != s.end()) {
                for (auto k : s[hash1]) {
                    if (comp(nums1, nums2, k, i, p)) return true;
                }
            }
            i++;
            m++;
        }

        return false;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        RollingHash r1 = RollingHash(nums1);
        RollingHash r2 = RollingHash(nums2);

        int i = 0, j = nums1.size();
        int ans = 0;
        while(i <= j) {
            int m = (i + j)/2;
            int found = solve(nums1, nums2, m, r1, r2);
            if (found) {
                ans = max(ans, m); 
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return ans;
    }
};