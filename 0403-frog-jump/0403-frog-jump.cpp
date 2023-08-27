class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int, set<int> >m;
        int n=stones.size();
        m[stones[0]+1].insert(1);
        
        for(int i=1; i<n; i++){
            int stone=stones[i]; 
            //traverse on set of that element
            for(auto it: m[stone]){
                // int a=it-1, b=it, c=it+1; //these steps can be taken from that stone
                m[stone+it].insert(it);
                m[stone+it-1].insert(it-1);
                m[stone+it+1].insert(it+1);
            }
        }
        //check whether reached end with atleast 1 step
        
        if(m[stones[n-1]].size()>0)return true;
        return false;
    }
};