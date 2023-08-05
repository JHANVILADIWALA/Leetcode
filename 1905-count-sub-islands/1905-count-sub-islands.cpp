class Solution {
public:
     void dfs( int r, int c,vector<vector<int>>& a, vector<vector<int>>& b,vector<vector<int>>&vis , bool &flg){
        vis[r][c]=1;
        // ls.push_back(node);
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        
         if(a[r][c]==0)flg=false;
        //neighbours
        for(int i=0; i<4; i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nr<b.size() && nc>=0 && nc<b[0].size() && b[nr][nc]==1 && !vis[nr][nc]){
                vis[nr][nc]=1;
                dfs(nr,nc,a,b,vis,flg);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ckt=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && b[i][j]==1 && a[i][j]==1){
                    bool flg=true;
                    dfs(i,j,a,b,vis,flg);
                    if( flg==true ){ ckt++; cout<<i<<" "<<j<<endl;}
                }
            }
        }
        return ckt;
    }
};