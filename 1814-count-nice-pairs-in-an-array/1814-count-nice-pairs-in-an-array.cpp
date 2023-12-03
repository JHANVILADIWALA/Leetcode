class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long ans=0,n=nums.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            int a=nums[i];
            string reva=to_string(a);
            reverse(reva.begin(), reva.end());
            int rva=stoi(reva);
            int val=a-rva;
            m[val]++;
        }
        for(auto it:m){
            long long num=it.second-1;
            ans=(ans+num*(num+1)/2)%1000000007;
        }
        return ans;
    }
};