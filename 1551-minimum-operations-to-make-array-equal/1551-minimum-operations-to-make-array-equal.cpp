class Solution {
public:
    int minOperations(int n) {
        int ckt=1, sum=0;
        if(n%2==0){
            for(int i=0; i<n/2; i++){
                sum+=ckt;  ckt= 2*(i+1) + 1;
            }
        }
        else{
            for(int i=0; i<n/2; i++){
                sum+=abs(n-ckt);  ckt= 2*(i+1) + 1;
            }
        }
        
        return sum;
    }
};