class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        // sliding window
        if(k<=1) return 0;
        int prod=1;
        int j=0, i=0;
        int ans=0;
        while( j<a.size() ){
            prod*=a[j];
            while(prod>=k){
                prod/=a[i];
                i++;
            }
            ans += j-i+1 ;
            j++;
        }
        return ans;
    }
};