class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        if(n==2)return 91;
        int mul=8;
        int ckt=n-2;
        int ans=91;
        int val=81;
        while(ckt>0){
             val*=mul; mul--; ckt--;
            ans+=val;
        }
        return ans;
    }
};