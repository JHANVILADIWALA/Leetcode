class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        
        int n = w.size();
        
        vector<int>v;
        for(int i=0; i<n-1; i++){
            v.push_back(w[i]+w[i+1]);
        }
        sort(v.begin(), v.end());
        
        long long minsum=0, maxsum=0;
        //k teams -> k-1 partitions
        for(int i=0; i<k-1; i++){
            minsum+=v[i];
            maxsum+=v[ v.size()-1-i];
        }
        
        
        return maxsum-minsum;
    }
};