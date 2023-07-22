class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //using map
        map<int,int>m;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
          
            int a=nums[i];
            int b=target-nums[i];
             // cout<<a<<" "<<m[a]<<endl;
            auto it=m.find(b);
            if(it!=m.end() ){ //found
                cout<<m[b]<<" "<<m[a]<<" "<<endl;
                ans.push_back(m[b]);
                ans.push_back(i);
                break;
            }
            else{
                m[a]=i;
            }
        }
        cout<<":/";
        return ans;
    }
};