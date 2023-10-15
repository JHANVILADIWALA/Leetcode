class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>p(n, vector<int>(m));
        
        long long prod=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               p[i][j]=prod;
                prod=(prod*grid[i][j])%12345;
            }
        }
         prod=1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
               p[i][j] = (p[i][j] * prod) % 12345;
               prod=(prod*grid[i][j])%12345;
            }
        }
        return p;
    }
};