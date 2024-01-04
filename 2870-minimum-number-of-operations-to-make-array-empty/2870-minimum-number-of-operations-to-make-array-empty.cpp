class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int ans=0;
        
        for(auto it: m){
            int b=it.second;
            if(it.second==1)return -1;
            if(it.second%3==0)ans+=it.second/3;
            else{
                int x=b/3;
                x*=3;
                if(b-x<2)x-=3;
                ans+=x/3;
                int rem=b-x;
                ans+=rem/2;
            }
        }
        return ans;
    }
};