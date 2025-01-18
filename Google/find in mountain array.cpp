/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lo = 0, hi = mountainArr.length() -1, mid;
        while(hi - lo > 1){
            mid = (hi + lo)>>1;
            int x = mountainArr.get(mid), xm1 = mountainArr.get(mid-1);
            if(x > xm1) lo = mid;
            else  hi = mid;
        }
        int mountainIdx;
        if(mountainArr.get(lo) > mountainArr.get(hi)) mountainIdx = lo;
        else mountainIdx = hi;

        lo = 0, hi = mountainIdx;
        while(hi - lo > 1){
            mid = (hi + lo)>>1;
            int x = mountainArr.get(mid);
            if(x == target) return mid;
            if(x < target) lo = mid;
            else hi = mid;
        }
        if(mountainArr.get(lo) == target) return lo;
        if(mountainArr.get(hi) == target) return hi;

        lo = mountainIdx; hi = mountainArr.length() -1;
        while(hi - lo > 1){
            mid = (hi+lo)>>1;
            int x = mountainArr.get(mid);
            if(x == target) return mid;
            if(x < target) hi = mid;
            else lo = mid;
        }
        if(mountainArr.get(lo) == target) return lo;
        if(mountainArr.get(hi) == target) return hi;
        return -1;
    }
};