class Solution {
public:
    int numberOfMatches(int n) {
        int ckt=0;
        while(n>1){
            if(n&1){
                ckt+=n/2; n=n/2+1;
            }
            else{
                ckt+=n/2; n=n/2;
            }
        }
        return ckt;
    }
};