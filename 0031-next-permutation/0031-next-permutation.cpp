class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int ind=-1;
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind=i; break;
            }
        }
        //ind still -1 means its the largest permutation currently
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //searching for number grreater than nums[ind]
        for(int i=n-1; i>ind; i--){
            if(nums[ind]<nums[i]){
                swap(nums[ind], nums[i]);
                break;
            }
        }
        
        //now reversing the right part
        reverse(nums.begin()+ind+1, nums.end());
        return;
    }
};