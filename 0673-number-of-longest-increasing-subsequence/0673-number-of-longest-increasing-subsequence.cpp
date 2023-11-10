class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>t(n,1); //length of lis ending at i
        vector<int>count(n,1);//counts of lis 
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(t[j]+1>t[i]){ //found greater length
                    t[i]=t[j]+1; count[i]=count[j];
                }
                else if(t[i]==t[j]+1){ //f
                    t[i]=t[j]+1; count[i]+=count[j];
                }
                }
            }
        }
        int maxval=*max_element(t.begin(), t.end());
        int result=0;
        for(int i=0; i<n; i++){
            if(t[i]==maxval)result+=count[i];
        }
        return result;
    }
};