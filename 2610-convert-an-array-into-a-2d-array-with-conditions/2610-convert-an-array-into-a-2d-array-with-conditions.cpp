class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int maxi =0;
        for(auto it:m){
            maxi= max(maxi, it.second);
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<vector<int>>ans(maxi);
        
        for(auto it:m){
            for(int i=0; i<it.second; i++){
                ans[i].push_back(it.first);
            }
            
        }
       
        return ans;
    }
};