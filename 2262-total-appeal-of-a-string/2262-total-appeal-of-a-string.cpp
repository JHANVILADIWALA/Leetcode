class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        int n=s.size();
        map<char,set<int>> index;
        
        for(int i=0;i<n;i++){
            index[s[i]].insert(i);
        }
        
        for(int i=0;i<s.size();i++){
            
            long long l,r;
            auto it=index[s[i]].find(i);
            if(it==index[s[i]].begin()){
                l=i+1,r=n-i;
            }
            else{
                int prev=*(--it);
                l=i-prev,r=n-i;
            }
            ans+=(l*r);
        }
        return ans;
    }
};
