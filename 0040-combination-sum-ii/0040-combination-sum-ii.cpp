class Solution {
private:
    void solve(int ind, int target, vector<int>& arr,vector<vector<int>>&ans, vector<int>&v ){
        if(target==0){
          ans.push_back(v);
          return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            solve(i+1,target-arr[i],arr, ans,v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>v;
        sort( candidates.begin(),candidates.end()  );
        solve(0,target,candidates, ans,v);
        return ans;

    }
};