class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>>ans;
        unordered_map< int, vector<int> >m;
        
        for(int i=0; i<gs.size(); i++){
            m[gs[i]].push_back(i);
        }
        for(auto it:m){
            int size=it.first;
            vector<int>v=it.second;
            int k=0;
            int parts=v.size()/size;
            for(int i=0; i<parts; i++){
                vector<int>temp;
                for(int j=0; j<size; j++){temp.push_back(v[k++]);}
                ans.push_back(temp);
            }
        }
        return ans;
    }
};