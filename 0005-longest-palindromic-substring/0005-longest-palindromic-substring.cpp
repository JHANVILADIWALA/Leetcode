class Solution {
public:
    string longestPalindrome(string s) {
        string longest="";
        int n=s.size();
        int j;
        
        for(int i=0;i<n;i++){
            j=n-1;
            while(i<j){
                if(s[i]==s[j] && longest.size()<j-i+1){
                    //means a possible answer
                    //check if substring from i to j is palindrome
                    string subs= s.substr(i,j-i+1);
                    string revsubs=subs;
                    reverse(revsubs.begin(),revsubs.end());
                    if(subs==revsubs){
                        //means palindrome
                        longest=subs;
                    }
                }
                j--;
            }
        }
        if(longest.size()==0){
            //means no palin found
            longest+=s[0];
        }
        return longest;
    }
};