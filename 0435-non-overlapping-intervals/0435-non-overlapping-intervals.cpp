class Solution {
public:
     static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(), v.end(), cmp);
        int ckt=0;
        int a=v[0][0];
        int b=v[0][1];
        
        for(int i=1; i<n; i++){
            if(v[i][0]>=b){
                ckt++;
                a=v[i][0];
                b=v[i][1];
            }
        }
        return n-ckt-1; 
    }
};