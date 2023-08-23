class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        int total=0;
        int n=g.size();
        //sum of non grumpy i.e g[i]=0
        for(int i=0; i<n; i++){
            if(g[i]==0)total+=c[i]; //non grumpy will be there 
        }
        
        //now running sliding window and taking sumof grumpy (max sum)
        int ans=0, sum=0;
        for(int i=0; i<k; i++){
            if(g[i]==1)sum+=c[i];
        }
        ans=max(ans, sum);
        int i=0, j=k;
        while(j<n){
           ans=max(ans, sum);
           if(g[i]==1)sum-=c[i];
           if(g[j]==1)sum+=c[j];
            i++; j++;
        }
        ans=max(ans, sum);
        return total+ans;
    }
};