class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>m;
        for(auto it: paths){
            m[it[0]]++;
        }
        string ans;
        for(auto it:paths){
            if(m[it[1]]<1)ans=it[1];
        }
        return ans;
    }
};