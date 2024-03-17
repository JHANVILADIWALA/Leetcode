class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {
        int i=0;
        vector<vector<int>>ans;
        int n=intervals.size();
        
        while(i<n){
            if(intervals[i][1]<newi[0]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newi[1]){
                break;
            }
            else{
                //merge and move fwd
                newi[0]=min(newi[0],intervals[i][0]);
                newi[1]=max(newi[1],intervals[i][1]);
            }
            i++;
        }
        
        ans.push_back(newi);
        //insert all remaining elements
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};