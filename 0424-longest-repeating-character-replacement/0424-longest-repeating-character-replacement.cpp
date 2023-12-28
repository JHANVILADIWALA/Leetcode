class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>ckt(26, 0);
        int i=0;
        int maxckt=0;
        int n=s.size();
        
        int ans=0;
        for(int j=0; j<n; j++){
            ckt[s[j]-'A']++;
            maxckt=max(maxckt, ckt[s[j]-'A']);
            
            while(j-i+1-maxckt>k){
                ckt[s[i]-'A']--;  i++;
                
                for(int i=0; i<26; i++){
                    maxckt=max(maxckt, ckt[i]);
                }
            }
            ans=max(ans, j-i+1);
        }
        return ans;
    }
};