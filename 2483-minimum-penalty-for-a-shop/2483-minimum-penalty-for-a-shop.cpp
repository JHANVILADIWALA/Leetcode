class Solution {
public:
    int bestClosingTime(string s) {
        vector<int>no,yes;
        int n=s.size();
        int maxy=0;
        for(int i=0;i<n;i++){
            if(s[i]=='Y') maxy++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
          if(s[i]=='N') sum++;
          no.push_back(sum);
        }
         sum=0;
        for(int i=n-1;i>=0;i--){
          
          yes.push_back(sum);
          if(s[i]=='Y') sum++;
        }
        reverse(yes.begin(),yes.end());
        int minsum=INT_MAX;
        int ans=0;
        vector<pair<int,int>>v;
        v.push_back( { maxy ,0});
        for(int i=0;i<n;i++){
            int tempsum=no[i]+yes[i];
            if(tempsum<minsum){
                minsum=tempsum;
                v.push_back( { tempsum , i+1 } );
            }
        }
        sort(v.begin(),v.end());
        return v[0].second;
    }
};