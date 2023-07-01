class Solution {
public:
    int hammingWeight(uint32_t N) {
        int ckt=0;
       for(int i=31 ; i>=0; i--){
           if( N & 1 == 1)ckt++;
           N>>=1;
       }
       return ckt;
    }
};