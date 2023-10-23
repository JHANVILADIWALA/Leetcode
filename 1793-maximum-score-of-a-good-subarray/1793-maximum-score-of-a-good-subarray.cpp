class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k, j=k, n=nums.size();
        int result=nums[k], currmin=nums[k];
        
        while(i>0 || j<n-1){
            int leftvalue=0, rightvalue=0;
            if(i>0)leftvalue=nums[i-1];
            if(j<n-1)rightvalue=nums[j+1];
            
            if(leftvalue>rightvalue){
                i--;
                currmin=min(currmin, nums[i]);
            }
            else{
                j++;
                currmin=min(currmin, nums[j]);
            }
            result=max(result, currmin*(j-i+1));
        }
        
        return result;
    }
};