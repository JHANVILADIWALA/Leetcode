class Solution {
public:
    long long countVowels(string s) {
        long long ans=0;
        int n=s.size();
        // 0 1 2 3 4   n=5
        //   x
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u'){
                long long left=i+1;
                long long right=n-i;
                ans+=left*right;
            }
        }
        return ans;
    }
};