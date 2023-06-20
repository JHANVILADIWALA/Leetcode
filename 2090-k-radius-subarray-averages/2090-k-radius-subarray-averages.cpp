class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n= nums.size();
        vector<int>ans(n,-1);
        long long denom = 2*k + 1 ;
        if(denom>n)return ans;
        long long end=denom;
        long long start=0;
        long long numer=0;
        
        for(int i=0;i<denom;i++){
            numer+= nums[i];
        }
        for(int i=k;i<n-k;i++){
            
            ans[i]= numer/denom;
            if( end<n ){ numer-=nums[start++];
            numer+=nums[end++];}
             else break;
        }
        return ans;
        
     
            
            
    }
};