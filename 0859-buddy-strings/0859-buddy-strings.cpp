class Solution {
public:
    bool buddyStrings(string s, string goal) {
       int ckt=0;
        map<int,int>m;
        
        string x=s, y=goal;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if(x!=y)return false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i])ckt++;
            else m[s[i]]++;
        }
        int maxi=0;
        for(auto it:m){
            maxi=max(maxi, it.second);
        }
        if(ckt==2 )return true;
        if(maxi>=2 && s==goal)return true;
        return false;
    }
};