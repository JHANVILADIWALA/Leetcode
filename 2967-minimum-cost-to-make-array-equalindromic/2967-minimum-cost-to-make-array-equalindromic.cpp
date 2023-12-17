class Solution {
public:
    bool ispal(int n) 
{ 
    int reverse = 0; 
    int temp = n; 
    while (temp != 0) { 
        reverse = (reverse * 10) + (temp % 10); 
        temp = temp / 10; 
    } 
    return (reverse 
            == n); 
} 
    long long fn(vector<int>& nums, int x){
        long long ans=0;
        for(auto it:nums){
            ans+=abs(it-x);
        }
        return ans;
    }
   
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        int mid1=nums[n/2]; int mid2=mid1;
        
        while(!ispal(mid1))mid1--;
        while(!ispal(mid2))mid2++;
        long long cost1=fn(nums, mid1), cost2=fn(nums, mid2);
        return min(cost1, cost2);
    }
};