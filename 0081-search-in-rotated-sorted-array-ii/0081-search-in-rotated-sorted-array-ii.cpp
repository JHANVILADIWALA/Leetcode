class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); 
        
        //applying binary search
        bool ans=false;
        
        int start=0, end=nums.size()-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target){
                ans=true;
                break;
            }
            else if(nums[mid]>target)end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
};