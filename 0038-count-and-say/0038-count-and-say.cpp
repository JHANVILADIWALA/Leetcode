class Solution {
public:
    string convert(string s){
        string ans="";
        int ckt=0;ckt++;
        for(int i=1; i<s.size(); i++){
            if(s[i-1]!=s[i]){
                ans+=to_string(ckt);
                ans+=s[i-1];
                ckt=1;
            }
            else ckt++;
        }
        int n=s.size();
        if(ckt>0){
                ans+=to_string(ckt);
                ans+=s[n-1];
        }
        return ans;
    }
    string countAndSay(int n) {
        // 1
        // 11
        // 21
        // 1211
        // 111221
        string a="1";
        if(n==1)return a;
        
        for(int i=0; i<n-1; i++){
            string s=convert(a);
            a=s;
        }
        return a;
    }
};