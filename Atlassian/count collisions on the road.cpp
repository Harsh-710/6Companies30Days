class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, n= directions.size();
        string stations;

        for(int i=0; i< directions.size(); i++){
            if(i<n-1 and directions[i] == 'R' and directions[i+1] == 'L'){
                stations.push_back('S');
                ans += 2;
                i++;
            }else{
                stations.push_back(directions[i]);
            }
        }

        int right = 0;
        bool isStationOnLeft = false;
        for(char c: stations){
            if(c == 'L' and isStationOnLeft) ans++;
            if(c == 'R') right++;
            if(c == 'S'){
                isStationOnLeft = true;
                ans += right;
                right = 0;
            }
        }

        return ans;
    }
};