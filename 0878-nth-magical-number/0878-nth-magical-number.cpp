class Solution {
public:
    #define mod 1000000007
    int nthMagicalNumber(int n, int a, int b) {
        int lcm=(a*b)/__gcd(a,b);
        long long l=min(a,b), r=n*1LL*min(a,b);
        long long ans=0;
        
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long ckt=mid/a + mid/b - mid/lcm;
            
            if(ckt<n)l=mid+1;
            else{
                ans=mid%mod;
                r=mid-1;
            }
        }
        return ans;
    }
};