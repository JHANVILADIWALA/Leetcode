class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1);
        //t[i]=ith ugly number
        //t[n]=nth ugly
        
        int i2,i3,i5;
        i2=1;i3=1;i5=1;
        
        //1st ugly number is 1
        t[1]=1;
        for(int i=2; i<=n; i++){
            int i2un=t[i2]*2;
            int i3un=t[i3]*3;
            int i5un=t[i5]*5;
            
            int minun=min({i2un,i3un,i5un});
            t[i]=minun;
            
            if(minun==i2un)i2++;
            if(minun==i3un)i3++;
            if(minun==i5un)i5++;
        }
        return t[n];
    }
};