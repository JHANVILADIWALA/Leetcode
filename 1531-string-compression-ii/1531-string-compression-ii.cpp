int t[101][27][101][101]; //heap
class Solution {
public:
    
    int solve(string&s, int i, int prevchar, int freq, int k){
        //base case
        if(k<0)return INT_MAX;
        if(i>=s.size())return 0;
        
        if(t[i][prevchar][freq][k]!=-1){
            return t[i][prevchar][freq][k];
        }
        
        //option 1
        int delete_i= solve(s, i+1, prevchar, freq, k-1);
        
        //option 2 .. keep
        int keep_i=0;
        
        if(prevchar != s[i]-'a'){
            keep_i= 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        else{
            int onemoreaddn=0;
            if(freq==1 || freq==9 || freq==99){
                onemoreaddn=1;
            }
            keep_i= onemoreaddn + solve(s, i+1, prevchar, freq+1, k);
        }
        return t[i][prevchar][freq][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0 , k);
    }
};