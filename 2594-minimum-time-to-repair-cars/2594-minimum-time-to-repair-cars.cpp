#define ll long long
class Solution {
public:
    bool fn( ll t, vector<int>& ranks , int cars ){
        ll count=0;
        for(int i=0; i<ranks.size(); i++){
            ll x=sqrt(t/ranks[i]);
            count+=x;
        }
        if(count>=cars)return true;
        else return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        sort(ranks.begin(), ranks.end());
        
        ll left=0, right=1e14;
        
        while(left<right){
            ll mid=left + (right-left)/2;
            if(fn(mid, ranks, cars)==true)right=mid;
            else left=mid+1;
        }
        return left;
    }
};