class Solution {
public:
    int lcs(string x, string y, int n , int m){
        int t[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1]==y[j-1])t[i][j]=1+t[i-1][j-1];
                else{
                    t[i][j]=max( t[i-1][j], t[i][j-1] );
                }
            }
        }
        return t[n][m];
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        if( lcs(s,t,n,m) == n)return true;
        return false;
    }
};