class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>allwin,onelost;
        unordered_map<int,vector<int>>m; //1->win, 0->loss
        
        for(auto it: matches){
            int win=it[0], loss=it[1];
            m[win].push_back(1); m[loss].push_back(0);
        }
        for(auto it: m){
            int num=it.first;
            vector<int>v=it.second;
            int win=0, loss=0;
            for(auto i: v){
                if(i==1)win++;
                else loss++;
            }
            if(win>0 && loss==0 && win==v.size()){
                allwin.push_back(num);
            }
            else if(loss==1){
                onelost.push_back(num);
            }
        }
        sort(allwin.begin(), allwin.end());
        sort(onelost.begin(), onelost.end());
        vector<vector<int>>ans;
        ans.push_back(allwin); ans.push_back(onelost);
        return ans;
    }
};