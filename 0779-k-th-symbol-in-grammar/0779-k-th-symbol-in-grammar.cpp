class Solution {
public:
    int fn(int n, int k){
        if(n==1 || k==1)return 0;//base case
        
        int length=pow(2,n-1);
        int mid=length/2;
        
        if(k<=mid)return fn(n-1, k);
        else return 1-fn(n-1, k-mid); //second half is complement of prev string
        
    }
    int kthGrammar(int n, int k) {
        return fn(n,k);
    }
};