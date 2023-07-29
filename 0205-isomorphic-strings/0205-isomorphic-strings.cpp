class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,char>m; //keeps which are mapped
        map<char,bool>used; //keeps track of used chars
        for(int i=0; i<n; i++){
            if(m.find(s[i])!=m.end()){ //found
                if(m[s[i]]!=t[i])return false;
            }
            else{
               if(used[t[i]]==false) {
                   m[s[i]]=t[i]; used[t[i]]=true;
                                     }
                else return false;
            }
        }
        return true;
    }
};