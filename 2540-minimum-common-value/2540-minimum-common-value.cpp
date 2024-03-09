class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto it: nums1)m[it]++;
        
        for(auto it: nums2){
            if(m.find(it)!=m.end())return it;
        }
        return -1;
    }
};