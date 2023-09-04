class Solution {
public:
    bool check(int k, vector<int>& w, int d){
        int currdays=1, tempsum=0;
        
        for(int i=0; i<w.size(); i++){
            tempsum+=w[i];
            if(tempsum>k){
                currdays++;
                tempsum=w[i];
            }
        }
        
        if(currdays<=d)return true;
        return false;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int n=w.size();
        int sum=0;
        int maxi=0;
        for(int i=0; i<n; i++)sum+=w[i];
        for(int i=0; i<n; i++)maxi=max(maxi,w[i]);
        int left=maxi, right=sum;
        
        while(left<right){
            int mid= left + (right-left)/2;
            if(check(mid, w, d)==true)right=mid;
            else left= mid+1;
        }
        return left;
    }
};