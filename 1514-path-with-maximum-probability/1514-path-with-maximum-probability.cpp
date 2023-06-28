class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector< pair<int,double> >>graph(n);

        //creating graph
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x].push_back({y,succProb[i]});
            graph[y].push_back({x,succProb[i]});
        }

        //dijkstra's algo
        vector<double>path(n,0.0);
        path[start] = 1.0 ;
        queue< int >q;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            //neighbours
            for(auto it:graph[curr]){
                double currnode = it.first;
                double currprob = it.second;
                double newprob = path[curr]*currprob;

                if(newprob > path[currnode]){
                    path[currnode]=newprob;
                    q.push(currnode);
                }
            }
        }
        return path[end];

    }
};