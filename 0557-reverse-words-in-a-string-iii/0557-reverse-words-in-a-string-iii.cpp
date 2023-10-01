class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' ')temp+=s[i];
            else{
                v.push_back(temp);
                temp="";
            }
        }
        v.push_back(temp);
        string ans="";
        for(auto it: v){
            reverse(it.begin(), it.end());
            ans+=it;
            ans+=" ";
            cout<<it<<endl;
        }
        ans.pop_back();
        // int n=v.size();
        // for(int i=0; i<n; i++){
        //     ans+=v[i];
        //     if(i!=n-1)ans+=" ";
        // }
        return ans;
    }
};