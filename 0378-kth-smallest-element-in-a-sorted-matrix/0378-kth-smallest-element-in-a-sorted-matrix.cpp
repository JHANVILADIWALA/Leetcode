class Solution {
public:
    int kthSmallest(vector<vector<int>>& grid, int k) {
       priority_queue<int>pq; 
        
       int n=grid.size();
       int m=grid[0].size();
        
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               pq.push(grid[i][j]);
               if(pq.size()>k)pq.pop();
           }
       }
        return pq.top();
    }
};