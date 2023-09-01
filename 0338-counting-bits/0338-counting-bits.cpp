class Solution {
public:
    int fn(int n){
        int ckt=0;
        while(n){
            ckt+=n&1;
            n>>=1;
        }return ckt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n; i++){
            ans.push_back(fn(i));
        }
        return ans;
    }
};