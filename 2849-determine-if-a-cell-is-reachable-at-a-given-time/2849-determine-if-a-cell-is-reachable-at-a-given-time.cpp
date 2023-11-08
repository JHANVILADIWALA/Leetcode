class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int maxi= max(abs(fx-sx), abs(fy-sy));
        if( maxi>t  || ( maxi==0 && (t==1)))return false;
        else return true;
    }
};