class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto it: arr){
            m[it]++;
        }
        vector<int>v;
        for(auto it: m){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int n=v.size();
        
        for(int i=0; i<n; i++){
            if(v[i]<=k){
                k-=v[i];
                v[i]=0;
            }    
        }
        int ckt=0;
        for(auto it: v){
            if(it!=0)ckt++;
        }
        return ckt;
    }
};