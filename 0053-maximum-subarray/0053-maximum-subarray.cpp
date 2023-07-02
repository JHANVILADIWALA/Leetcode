class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        //brute force : 3 for loops (n^3)
    long long ans = LONG_MIN ;
    long long sum = 0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>ans){
            ans=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return ans;
    }
};