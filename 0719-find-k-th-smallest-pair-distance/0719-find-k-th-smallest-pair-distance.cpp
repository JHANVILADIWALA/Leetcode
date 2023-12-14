class Solution {
public:
    //this fn checks if the (total no of pairs with diff <=mid) is
    // >=k or not
    bool check(vector<int>& nums, int mid, int k){
        //how many pairs have diff less than or equal to mid
        int total=0, n=nums.size();
        
        int j=0; //right pointer
        
        for(int i=0; i<n; i++){
            while(j<n && nums[j]-nums[i]<=mid)j++;
            j--;
            total+=(j-i);
        }
        if(total>=k)return true;
        else return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=-1;
        
        int l=0, r=nums[n-1]-nums[0];
        while(l<=r){
            int mid=(l+r)/2;
            
            if(check(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }return ans;
    }
};