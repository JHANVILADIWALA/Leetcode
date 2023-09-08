class Solution {
public:
    bool check(int mid, vector<int>& nums, int maxop){
        int currop=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%mid==0) currop+= nums[i]/mid-1;
            else currop+= nums[i]/mid;
        }
        if(currop<=maxop)return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxop) {
        int left=1, right=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n ;i++)right=max(right, nums[i]);
        
        while(left<right){
            int mid= left + (right-left)/2; 
            if(check(mid, nums, maxop)==true)right=mid;
            else left=mid+1;
        }
        return left;
    }
};