class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        int n=bank.size();
        int m=bank[0].size();
        if(bank.size()==1) return 0;
        
        int ans=0;
        for(int i=0;i<n;i++){
            int ckt=0;
            for(int j=0;j<m;j++){
               if(bank[i][j]=='1') ckt++;
            }
            if(ckt>0) v.push_back(ckt);
        }
        if(v.size()==1||v.size()==0) return 0;
            for(int i=0;i<v.size()-1;i++){
                ans+=v[i]*v[i+1];
            }
        
        return ans;
    }
};