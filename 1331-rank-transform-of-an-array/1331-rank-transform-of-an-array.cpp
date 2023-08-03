class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>ans; 
       set<int>s(arr.begin(), arr.end());
       vector<int>temp;
        for(auto it:s){
            cout<<it<<" ";
            temp.push_back(it);}
        
        for(int i=0; i<arr.size(); i++){
            int lb= lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            ans.push_back(lb+1);
        }
        return ans;
    }
};