class Solution {
    
    int fn(int ind,int flg,vector<int>&nums1,vector<int>&nums2,vector<vector<int>> &dp){
        
        if(ind==nums1.size()) return 0;
        
        int swap=1e9,notSwap=1e9;
        
        if(dp[ind][flg]!=-1) return dp[ind][flg];
        
        // can i swap or not
        int ele1,ele2;
        ele1=nums1[ind-1],ele2=nums2[ind-1];
        
        if(flg==1){
            int temp=ele1;
            ele1=ele2;
            ele2=temp;
        }
        
        if(nums1[ind]>ele1 && nums2[ind]>ele2){ // i know i can swap or not
            
            if(nums1[ind]>ele2 && nums2[ind]>ele1){
                swap=1+fn(ind+1,1,nums1,nums2,dp);
            }
            notSwap=fn(ind+1,0,nums1,nums2,dp);
            
        }else{ // i have to swap
            if(nums1[ind]>ele2 && nums2[ind]>ele1){
                swap=1+fn(ind+1,1,nums1,nums2,dp);
            }
        }
        return dp[ind][flg]=min(swap,notSwap);
    }
    
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
        
        int a=fn(1,0,nums1,nums2,dp);
        int b=1+fn(1,1,nums1,nums2,dp);
        return min(a,b);
    }
};

