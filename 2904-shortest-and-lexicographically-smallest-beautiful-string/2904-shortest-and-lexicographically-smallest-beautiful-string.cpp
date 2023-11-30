class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len=s.size()+1;
        int n=s.size();
        for(int i=0; i<n; i++){
            int ckt=0;
            
            for(int j=i; j<s.size(); j++){
                if(s[j]=='1')ckt++;
                if(ckt==k){
                    if(j-i+1<len){
                        len=j-i+1;
                        break;
                    }
                }
            }
        }
        string maxi="";
        for(int i=0; i<n; i++){
            int ckt=0;
            for(int j=i; j<s.size(); j++){
                if(s[j]=='1')ckt++;
                if(ckt==k){
                    if(j-i+1==len){
                        if(maxi==""){
                            maxi=s.substr(i,j-i+1);
                        }
                        else{
                            maxi=min(maxi, s.substr(i, j-i+1));
                        }
                    }
                }
            }
        }
        return maxi;
    }
};