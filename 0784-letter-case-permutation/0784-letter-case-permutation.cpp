#include<bits/stdc++.h>
class Solution {
public:
    vector<string>ans;
    void fn(int ind, string s){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        //check if character
        if(isalpha(s[ind])){
            s[ind]=tolower(s[ind]);
            fn(ind+1,s);
            s[ind]=toupper(s[ind]);
            fn(ind+1,s);
        }
        else fn(ind+1,s);
    }
    vector<string> letterCasePermutation(string s) {
        fn(0,s);
        return ans;
    }
};