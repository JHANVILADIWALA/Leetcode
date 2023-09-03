class Solution {
public:
    int fn(string a, string b){
        int ckt=0, move=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[ckt])ckt++;
            else move++;
            
            if(ckt==b.size())return move;
        }
        return 1e9;
    }
    int minimumOperations(string num) {
        int ans=0;
        for(auto it: num){
            if(it!='0')ans++;
        }
        reverse(num.begin(), num.end());
        ans=min(ans, fn(num, "00"));
        ans=min(ans, fn(num, "05"));
        ans=min(ans, fn(num, "52"));
        ans=min(ans, fn(num, "57"));
        
        return ans;
    }
};