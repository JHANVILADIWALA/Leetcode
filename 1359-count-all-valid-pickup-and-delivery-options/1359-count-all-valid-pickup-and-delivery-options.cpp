class Solution {
public:
    int countOrders(int n) {
        if(n==1)return 1;
        int mod=1e9+7;
        long long result=1;
        for(int i=2; i<=n; i++){
            int spaces=2*(i-1)+1;
            int temp=(spaces*(spaces+1)/2)%mod;
            result=(result*temp)%mod;
        }
        return result%mod;
    }
};