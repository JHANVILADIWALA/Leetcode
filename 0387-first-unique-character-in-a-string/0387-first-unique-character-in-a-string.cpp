class Solution {
public:
    int firstUniqChar(string s) {
       int n=s.size();
       unordered_map<int,int>m;
       for(int i=0;i<n;i++){
         m[s[i]]++;
       } 
       int ans=-1;
       for(int i=0;i<n;i++){
           if(m[s[i]]==1){
               ans=i;
               break;
           }
       }
       return ans;
    }
};