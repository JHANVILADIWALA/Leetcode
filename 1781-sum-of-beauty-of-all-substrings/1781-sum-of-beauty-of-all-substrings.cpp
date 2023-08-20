class Solution {
public:
    int beautySum(string s) {
        int n=s.size(), ans=0; 
        
        for(int i=0; i<n; i++){
            unordered_map<char,int>m;
            for(int j=i; j<n; j++){
                m[s[j]]++;
                int maxi=INT_MIN, mini=INT_MAX;
                //get max and min
                for(auto it:m){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                ans+=maxi-mini; 
            }
        }
        return ans;
    }
};