class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        
        int o=0, z=0;
        string a="", b="";
        
        for(int i=0; i<n; i++){
            if(i%2==0){
                a+='1'; b+='0';
            }
            else{
                a+='0'; b+='1';
            }
        }
        for(int i=0; i<n; i++){
            if(s[i]!=a[i])o++;
            if(s[i]!=b[i])z++;
        }
        return min(o,z);
    }
};