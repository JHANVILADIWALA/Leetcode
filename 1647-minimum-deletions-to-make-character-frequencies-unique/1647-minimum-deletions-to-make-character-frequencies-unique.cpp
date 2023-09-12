class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>ckt;
        unordered_set<int>freq;
        int ans=0;
        for(auto it:s)ckt[it]++;
        for(auto it:ckt){
            int x=it.second;
            while(x>0 && freq.find(x)!=freq.end()){
                x--;ans++;
            }
            freq.insert(x);
        }
        return ans;
    }
};