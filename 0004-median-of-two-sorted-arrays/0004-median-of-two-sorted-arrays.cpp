class Solution {
public:
    double findMedianSortedArrays(vector<int>& ar1, vector<int>& ar2) {
        vector<int>v;
        for(int i=0;i<ar1.size();i++){
             v.push_back(ar1[i]);
         }
        for(int i=0;i<ar2.size();i++){
             v.push_back(ar2[i]);
         }
        sort(v.begin(), v.end() );
         
        int n= ar1.size() + ar2.size();
        
        double ans;
        
        if(n%2==0) ans= (v[n/2] + v[n/2-1])/2.0;
        else ans= v[n/2];
        return ans;
    }
};