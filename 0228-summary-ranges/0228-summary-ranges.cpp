class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;

        string temp="";
        for(int i=0;i<n;i++){
            int j=i;
            while(j+1<n && nums[j]+1==nums[j+1])j++;
            //found breakage point

            //so push i and j in temp

            if(j>i){ //if diffrentt
            temp+=to_string(nums[i]);
            temp+="->";
            temp+=to_string(nums[j]);
            }
            
            //same -> add once
            else temp += to_string(nums[i]);
            

            //now push temp to ans
            ans.push_back(temp);

            //make temp empty
            temp="";
            i=j;
        }
        return ans;
    }
};