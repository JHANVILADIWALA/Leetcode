//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs( string x, string y, int n, int m){
        int t[n+1][m+1];
        for(int i=0; i<=n;i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max( t[i-1][j], t[i][j-1] );
                }
            }
        }
        return t[n][m];
    }
    int longestPalinSubseq(string a) {
         // LPS(a) = LCS(a, revofa);
         string revofa  = a;
          reverse(revofa.begin(), revofa.end());
         int n=a.size();
         return lcs( a , revofa , n , n );
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends