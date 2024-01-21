class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int v=*min_element(nums.begin(), nums.end());
        for(auto it: nums){
            if(it%v>0){
                //not a multiple of min elem
                return 1;
            }
        }
        int ckt=count(nums.begin(), nums.end(), v); //number of times v occur in nums
        return (ckt+1)/2;
    }
};