class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int n=s.size();
        set<int>st;
        int len=0;
        while(right<n){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]); left++;
            }
            st.insert(s[right]);
            len=max(len, right-left+1);
            right++;
        }
        return len;
    }
};