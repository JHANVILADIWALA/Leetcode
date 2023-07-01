class Solution {
public:
    bool isvalid( char ch, int r, int c , int n){
        if(ch=='R' && c+1<=n-1)return true;
        if(ch=='L' && c-1>=0) return true;
        if(ch=='U' && r-1>=0)return true;
        if(ch=='D' && r+1<=n-1)return true;
        return false;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans;
        int r= startPos[0];
        int c= startPos[1];
        
        for(int i=0; i<s.size(); i++){
            int ckt=0;
            int nr=r, nc=c;
            for(int j=i; j<s.size(); j++){
                if( isvalid(s[j], nr, nc,n)){
                    if(s[j]=='R'){
                        nc++;
                    }
                    if(s[j]=='L'){
                        nc--;
                    }
                    if(s[j]=='U'){
                        nr--;
                    }
                    if(s[j]=='D'){
                        nr++;
                    }
                    ckt++;
                }
                else break;
            }
            ans.push_back(ckt);
        }
        return ans;
    }
};