class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        
        for(int i: arr1){
            bool flag = false;
            for(int j: arr2){
                if(abs(i-j) > d) flag = true;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }

        return ans;
    }
};