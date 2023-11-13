class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        string ans;
        ans=s;
        
        vector<int>x;
        vector<char>y;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                x.push_back(i);
                y.push_back(s[i]);
            }
        }
        sort(y.begin(), y.end());
        
        for(int i=0; i<y.size(); i++){
            ans[x[i]]=y[i];
        }
        
        return ans;
    }
};