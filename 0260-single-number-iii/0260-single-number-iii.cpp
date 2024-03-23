class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        //int a;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==1) {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};