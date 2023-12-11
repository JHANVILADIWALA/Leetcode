class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int ckt=n/4;
        unordered_map<int,int>m;
        for(auto it:arr)m[it]++;
        int ans=-1;
        for(auto it:m){
            if(it.second>ckt){
                ans=it.first; break;
            }
        }return ans;
    }
};