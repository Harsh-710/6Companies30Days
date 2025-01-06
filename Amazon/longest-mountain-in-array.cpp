class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        if(n<3) return ans;
        for(int i=0; i< n-1; i++){
            if(arr[i] < arr[i+1]){
                int j=i;
                bool flag = false;
                while(j< n-1 and arr[j] < arr[j+1]) j++;
                while(j< n-1 and arr[j] > arr[j+1]){ j++; flag = true; }
                if(flag) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};