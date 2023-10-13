class Solution {
public:
    int fn(int start, int sum, int n){
        if(start>n){
            if(sum==n)return 1;
            else return 0;
        }
        
        int pick=1, notpick=1;
        if(sum+start<=n)pick=start*fn(start, sum+start, n);
        notpick=fn(start+1, sum, n);
        
        return max(pick,notpick);
    }
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        return fn(1,0,n);
    }
};