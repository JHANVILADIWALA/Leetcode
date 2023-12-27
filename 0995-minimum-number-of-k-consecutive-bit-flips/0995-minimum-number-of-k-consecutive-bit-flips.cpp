class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>flips(n,0);
        
        for(int i=0; i<n; i++){
            int currbit=nums[i];
            
            if(i>0){
                int prev=flips[i-1];
                int before;
                if(i-k>=0)before=flips[i-k];
                else before=0;
                
                int totalopr=prev-before;
                if(totalopr&1)currbit^=1;
            }
            if(currbit==0){
                if(i+k>n)return -1;
                flips[i]=1;
            }
            if(i>0){
                flips[i]+=flips[i-1];
            }
            nums[i]=1;
        }
        return flips[n-1];
    }
};