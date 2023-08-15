class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    priority_queue<int,vector<int>,greater<int>>pq;
                    int tempi=i, tempj=j;
                    while(tempi<n && tempj<m){
                        pq.push(mat[tempi][tempj]); 
                        // cout<<mat[tempi][tempj]<<endl;
                        tempi++; tempj++;
                    }
                    tempi=i; tempj=j;
                    cout<<pq.size();
                    while(!pq.empty()){
                        // cout<<"hiiiiiiiii"<<endl;
                        cout<<pq.top()<<" ";
                        ans[tempi][tempj]=pq.top(); pq.pop();
                        tempi++; tempj++;
                    }
                }
            }
        }
        return ans;
    }
};