class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>charind(26,0);
        int n=s.size();
        
        for(int i=0; i<n; i++){
            charind[s[i]-'a']=i;  //last index of evry character
        }
        
        vector<int>results;
        int maxind=-1, lastind=0;
        
        for(int i=0; i<n; i++){
            maxind=max(maxind, charind[s[i]-'a']);
            
            if(i==maxind){
                results.push_back(maxind-lastind+1);
                lastind=i+1;
            }
        }
        return results;
    }
};