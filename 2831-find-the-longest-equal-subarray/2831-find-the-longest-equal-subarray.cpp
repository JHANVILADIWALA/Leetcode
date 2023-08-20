class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxi=0;
        map<int,int>m;
        
        int i=0;
        for(int j=0; j<nums.size(); j++){
            m[nums[j]]++;
            maxi=max(maxi, m[nums[j]]);
            
            if( (j-i+1)-(maxi)>k){ //current subarray length - number of eq elements in subarray = elements that can be deleted
                m[nums[i]]--;
                i++;
            }
        }
        return maxi;
    }
};