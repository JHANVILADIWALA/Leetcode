class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>s;
        s.insert({0,0});
        int x=0, y=0;
        for(auto it: path){
            if(it=='N')y++;
            if(it=='E')x++;
            if(it=='W')x--;
            if(it=='S')y--;
            
            if(s.find({x,y})==s.end()){
                s.insert({x,y});
            }
            else return true;
        }
        return false;
    }
};