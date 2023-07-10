class Solution {
public:
    string lcs(string x, string y, int n, int m){
        
        //LCS TABLE MAKING
        int t[n+1][m+1];
        //first row and first col 0
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        //GETTING Longest common substring from table
        string s="";
        int i=n, j=m; //starting from t[n][m]
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){ //move to diag element after adding
                s.push_back(x[i-1]);
                i--;
                j--;
            }
            else{ //move to top or left element whichever is greater
                if(t[i-1][j]>t[i][j-1]){
                    s.push_back(x[i-1]); //put this also bz we have to get supersequence
                    i--;}
                else {
                    s.push_back(y[j-1]);
                    j--;}
            }
        }
        // check for remaining elements
        while(i>0){
            s.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(y[j-1]);
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
    string shortestCommonSupersequence(string x, string y) {
        int n=x.size();
        int m=y.size();
        return lcs(x,y,n,m);
    }
};