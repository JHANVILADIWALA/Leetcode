class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string temp="";
        int n=words.size();
        
        for(auto it:words){
            temp+= it[0];
        }
        if(temp==s)return true;
        else return false;
        
    }
};