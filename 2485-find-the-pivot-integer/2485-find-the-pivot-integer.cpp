class Solution {
public:
    int pivotInteger(int n) {
        long long total=0;
        for(int i=1; i<=n; i++){
            total+=i;
        }
        long long tillheresum=0;
        for(int i=1; i<=n; i++){
            tillheresum+=i;
            long long restsum=total-tillheresum+i;
            if(tillheresum == restsum)return i;
        }
        
        return -1;
    }
};