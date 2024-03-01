class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int ones=0, zeroes=0;
        for(auto it:s){
            if(it=='0')zeroes++;
            else ones++;
        }
        
        string ans="";
        ones--;
        while(ones--){
            ans+='1';
        }
        while(zeroes--){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};