class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        //storing rows count in map
        
        map< vector<int> , int > m;
        for(int i=0 ; i<grid.size() ; i++ ){
            m[grid[i]]++;
        }
        int ans=0;
        
        
        for(int i=0 ; i<grid[0].size() ; i++ ){
            //getting column in a vector 
            vector<int>v;
            for(int j=0;j<grid.size();j++){
                v.push_back(grid[j][i]);
            }
            ans+=m[v];
        }
        return ans;
    }
};