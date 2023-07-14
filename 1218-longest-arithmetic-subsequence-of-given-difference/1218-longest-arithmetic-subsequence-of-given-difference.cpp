class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d){
        unordered_map<int,int>m;
        int ans=0;
        
        for(int i=0; i<arr.size(); i++){
            int prev = arr[i] - d;
            
            //check if prev is present before arr[i]
            int ckt=0;
            if(m.count(prev)){ //is present
                ckt=m[prev];
            }
            m[arr[i]]=1+ckt; // if ckt was 0 that means not found else accordinly value is set
            ans=max(ans, m[arr[i]]);
        }
        return ans;
    }
};