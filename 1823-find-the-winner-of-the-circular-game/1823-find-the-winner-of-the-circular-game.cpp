class Solution {
public:
    int rec(int n, int k){
        if(n==1)return 0; //0-based indexing, 1 person left in end
        return (rec(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return rec(n,k)+1;  // convert to 1 based indexing
    }
};