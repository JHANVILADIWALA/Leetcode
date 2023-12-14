class Solution {
public:
    //checks whether a basket can contain candy with tastyness less than given
    bool check(vector<int>& price, int mintastiness, int k){
        int candy=1;
        int lastslctedcandy=0; //we will select first candy for sure
        //we want to select candies at max dist
        
        for(int i=1; i<price.size(); i++){
            if(price[i]-price[lastslctedcandy]>=mintastiness){
                candy++; //pick this candy
                lastslctedcandy=i;
            }
        }
        if(candy>=k)return true;
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int ans=-1, n=price.size();
        int l=0, r=1e9;
        
        //TTTTTFFFFF
        while(l<=r){
            int mid=(l+r)/2;
            if(check(price,mid,k)==true){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};