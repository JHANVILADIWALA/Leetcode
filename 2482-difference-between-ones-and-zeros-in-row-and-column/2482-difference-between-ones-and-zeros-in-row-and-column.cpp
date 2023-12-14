class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
       vector<vector<int>>ans;
       int n=grid.size();
       int m=grid[0].size();
       vector<int>oc(m+1);
       vector<int>yor(n+1);
       vector<int>zc(m+1);
       vector<int>zr(n+1);
       
       for(int i=0;i<n;i++){
           int sum=0;
           for(int j=0;j<m;j++){
               sum+=grid[i][j];
           }
           yor[i]=(sum);
           zr[i]=(m-sum);
       }
       //or , zr = n
       //oc , zc =m
       for(int j=0;j<m;j++ ){
           int sum=0;
           for(int i=0;i<n;i++){
               sum+=grid[i][j];
           }
           oc[j]=(sum);
           zc[j]=(n-sum);
       }
    // for(int j=0;j<m;j++){
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         sum+=grid[i][j];
    //     }
    //     oc.push_back(sum);
    //      zc.push_back(n-sum);
    // }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               grid[i][j]=yor[i]-zr[i]+oc[j]-zc[j];
           }
       }
       return grid;
    }
};