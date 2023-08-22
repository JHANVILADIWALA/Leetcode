#define mod 1000000007
class Solution {
public:
     
    long long power(long long x, long long y){
        if(y==0)return 1;
        
        long long ans = power(x,y/2);
        ans*=ans;   ans%=mod;
        if(y&1) ans*=x;
        ans%=mod;
        return ans;
        
    }
    int countGoodNumbers(long long n) {
        // even place options: 0 2 4 6 8  -->5
        // odd place options : 2 3 5 7    -->4
        long long odd= n/2;
        long long even=n/2 + n%2;
        
        return (( power(4,odd) * power(5,even) )%mod);
    }
};