class Solution {
public:
    bool canwalk( vector<vector<int>>& cells, int row, int col, int day ){
        
        int dx[4] = {0 , 0, -1, 1};
        int dy[4] = {1, -1,  0, 0};
        
        //BFS TRAVERSAL
        vector< vector<bool> >grid(row, vector<bool>(col,0)); // matrix with everything 0
        
        // make water till day
        for(int i=0 ; i<day; i++){
            grid[ cells[i][0]-1 ][ cells[i][1]-1 ] = 1; 
        }
        
        //now check whether we can walk from top to bottom
        
        queue<pair<int,int>>q;
        
        //put all land(0) of first row in queue
        //multisource bfs
        for(int c=0; c<col; c++){
            if(grid[0][c]==0){
                q.push({0,c});
                grid[0][c]=1;   // marking it as visited that i can't visit it again so make it water
            }
        }
        
        while(!q.empty()){
            auto r= q.front().first;
            auto c= q.front().second;
            q.pop();
            if( r==row-1 )return true; //reached bottom
            
            //traverse neighbours
            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if( nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==0){
                    //means valid move
                    grid[nr][nc]=1; //vis
                    q.push({ nr,nc });
                }
            }
        }
        return false;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        //brute force:
        //change block to water and check whether works fine or not
        //if not return day number
        //but bad time complexity
        
        //optimised:
        //binary search
        //bz suddendly stops after a point
        //this reduces time complexity...we discard half part at every step
        //------>APPLYING BINARY SEARCH ON cells
        // O( log(cells.size()) )   *   ( O(cells.size()) + O( BFS/DFS/row*col ))
        // TRAVERSE CELLS             ,  PUT WATER  ,       traverse matrix
        
        int left=1, right=cells.size();
        int ans=0;
        while(left<=right){
            int mid = left + (right-left)/2;
            //if u can walk then move to right
            //else search in left
            if( canwalk( cells, row, col, mid) ){  // BFS or DFS
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};