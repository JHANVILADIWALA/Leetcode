class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long ans=0;
       unordered_map<long long,long long>m;
        long long vsz=nums.size();
        for(int i=0; i<vsz; i++){
            m[nums[i]-i]++;
        }
        for(auto it:m){
            vsz-=it.second;
            ans+=(it.second*vsz);
        }
        return ans;
    }
};