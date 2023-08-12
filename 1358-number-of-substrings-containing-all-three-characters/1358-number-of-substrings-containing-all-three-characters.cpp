class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0, right=0, end=n-1;
        
        unordered_map<char,int>mp;
        
        int ckt=0;
        
        while(right!=n){
            mp[s[right]]++;
            
            //shrinking window from left
            while(mp['a'] && mp['b'] && mp['c']){ //till window is valid
                ckt += 1 + (end-right);
                mp[s[left]]--;
                left++; 
            }
            
            right++;
        }
        return ckt;
    }
};