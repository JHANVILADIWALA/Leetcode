class Solution {
public:
    long long check(long long n){
        return 12*(n*(n+1)*(2*n+1))/6;
    }
    long long minimumPerimeter(long long neededApples) {
       long long ans=neededApples;
        long long l=0, r=1e6;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)>=neededApples){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans*8;
    }
};