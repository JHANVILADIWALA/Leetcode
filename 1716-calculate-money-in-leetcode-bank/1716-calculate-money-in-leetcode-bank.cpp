class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        ans+=(n/7)*28;
        int k=n/7-1;
        ans+=(7*(k*(k+1)/2));
        if(n%7==0)return ans;
        
        int val=n/7;
        cout<<ans<<endl;
        for(int i=1; i<=n%7; i++){
            ans+=(i+val);
        }
        return ans;
    }
};