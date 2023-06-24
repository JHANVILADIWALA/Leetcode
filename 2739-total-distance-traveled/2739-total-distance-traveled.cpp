class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        if(mainTank<5) return mainTank*10;
        else{
            int ans=0;
            int ckt=0;
            while(true){
                if(ckt<5){
                    ckt++;
                    mainTank--;
                }
                else if(ckt==5){
                    ans+=50;
                    ckt=0;
                    additionalTank--;
                    
                    mainTank++;
                    if(mainTank <5){
                    ans+= mainTank * 10;
                    break;
                    }
                }
                if(additionalTank==0){
                    ans+=mainTank*10;
                    break;
                }
                 
            }
            return ans;
        }
    }
};