class Solution {
public:
    string convertToTitle(int cn) {
        string ans;
        while(cn>0){
            cn--;
            int rem= cn%26;
            cn/=26;
            ans+= rem + 'A';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};