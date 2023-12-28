class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        long long maxi=0;
        
        map<int,int>m;
        for(int i=0; i<k; i++){
            sum+=nums[i]; m[nums[i]]++;
        }
        if(m.size()==k){
            maxi=max(maxi, sum);
        }    
        cout<<sum<<endl;
        for(int j=k; j<nums.size(); j++){
            m[nums[j-k]]--; m[nums[j]]++;
            if(m[nums[j-k]]==0)m.erase(nums[j-k]);
            
            sum-=nums[j-k];  sum+=nums[j];
            if(m.size()==k){
            maxi=max(maxi, sum);
            }    
            cout<<m.size()<<" "<<sum<<endl;
        }
        return maxi;
    }
};