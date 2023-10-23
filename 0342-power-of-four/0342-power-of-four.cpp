class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        
//         bool ispowerof2=false;//condition 1
//         if((n&(n-1))==0)ispowerof2=true;
        
//         bool NminusOneisDivby3=false;
//         if( (n-1)%3==0 )NminusOneisDivby3=true;
        
        if((n&(n-1))==0 && (n-1)%3==0)return true;
        else return false;
        
    }
};