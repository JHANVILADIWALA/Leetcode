class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row,col;
        int n=mat.size();
        // int m=mat[0].size();
        map<int,vector<int>>m;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<mat[i].size(); j++){
                int key=i+j;
                m[key].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(auto it:m){
                reverse(it.second.begin(), it.second.end());
            for(auto elem: it.second)ans.push_back(elem);
        }
         return ans;   
    }
};