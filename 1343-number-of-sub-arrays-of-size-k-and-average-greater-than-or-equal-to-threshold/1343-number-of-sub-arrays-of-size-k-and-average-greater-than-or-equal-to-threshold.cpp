class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=arr[i];
        }
        int ans=0;
        if(sum/k>=t)ans++;
        for(int i=k; i<arr.size(); i++){
            sum+=arr[i];
            sum-=arr[i-k];
            if(sum/k>=t)ans++;
        }
        return ans;
    }
};