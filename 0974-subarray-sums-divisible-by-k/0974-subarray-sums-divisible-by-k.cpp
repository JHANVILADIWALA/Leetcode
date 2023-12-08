class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int sum=0;
        int n=nums.size();
        int ans=0;
        
        unordered_map<int,int>m; m[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)rem+=k;
            if(m.find(rem)==m.end()){//not already in map
                m[rem]++;
            }
            else{//already there
                ans+=m[rem];
                m[rem]++;
            }
        }
        return ans;
    }
};