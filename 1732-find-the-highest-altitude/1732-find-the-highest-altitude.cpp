class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans =0;
        int dist=0;
        for(int i=0;i<gain.size();i++){
               
               dist+=gain[i];
            ans=max(ans,dist);
        }
        return ans;
        
    }
};