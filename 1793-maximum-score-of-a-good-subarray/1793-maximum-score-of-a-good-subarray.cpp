class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k, j=k, n=nums.size();
        int result=nums[k], currmin=nums[k]; 
        
        while(i>0 || j<n-1){
            int leftvalue=0, rightvalue=0;//when i or j might go out of bound, assume the value at their newplace as 0 because nothing is present o out of bounds
            
            if(i>0)leftvalue=nums[i-1];
            if(j<n-1)rightvalue=nums[j+1]; 
            
            //always move towards that value which is greater
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