class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());
            int num=stoi(str);
            s.insert(num);
        }
        return s.size();
    }
};