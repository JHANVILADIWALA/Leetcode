class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(auto it: nums1)m[it]++;
        unordered_map<int,int>ans;
        
        for(auto it: nums2){
            if(m.find(it)!=m.end()){
                ans[it]++;
            }
        }
        
        vector<int>v;
        for(auto it: ans){
            v.push_back(it.first);
        }
        return v;
    }
};