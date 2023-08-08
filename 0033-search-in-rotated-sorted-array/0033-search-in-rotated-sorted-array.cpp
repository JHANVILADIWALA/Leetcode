class Solution {
public:
    int search(vector<int>& nums, int target) {
        // vector<int>v=nums;
        map<int,int>m;
        for(int i=0; i<nums.size(); i++)m[nums[i]]=i;
        sort(nums.begin(),nums.end()); 
        
        //applying binary search
        int ans=-1;
        
        int start=0, end=nums.size()-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target){
                ans=m[nums[mid]];
                break;
            }
            else if(nums[mid]>target)end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
};