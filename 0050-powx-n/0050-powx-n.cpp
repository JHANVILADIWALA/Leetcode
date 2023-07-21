class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long dupofn=n;//bec n will be destroyed
        if(dupofn<0) dupofn=-1*dupofn;//make it pos//long long me it is stored so that overflow does not occur in converting neg to pos
        //neg has more space int that pos int
        while(dupofn){
            //until dupofn becomes zero
            if(dupofn%2!=0){
              ans=ans*x;
              dupofn=dupofn-1;
            }
            else{
                x=x*x;
                dupofn=dupofn/2;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};