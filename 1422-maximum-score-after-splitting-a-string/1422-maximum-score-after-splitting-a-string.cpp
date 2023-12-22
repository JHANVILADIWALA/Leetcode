class Solution {
public:
    int maxScore(string s) {
        int ones=0, zeroes=0;
        int maxi=INT_MIN;
        
        for(auto it:s){
            if(it=='1')ones++;
        }
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0')zeroes++;
            else ones--;
            maxi=max(maxi, zeroes+ones);
        }
        return maxi;
    }
};