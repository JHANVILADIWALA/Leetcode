class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n=r.size(), m=c.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j]=min(r[i],c[j]);
                r[i]-=ans[i][j];
                c[j]-=ans[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<ans[i][j]<<" "; 
            }cout<<endl;
        }
        return ans;
    }
};