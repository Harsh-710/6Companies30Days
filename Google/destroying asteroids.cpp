class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;

        for(int i: asteroids){
            if(i > m) return false;
            m += i;
        }

        return true;
    }
};