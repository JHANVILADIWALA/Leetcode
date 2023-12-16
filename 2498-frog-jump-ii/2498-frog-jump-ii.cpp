class Solution {
public:
    //whether it is possible to reach start position back with jumps<=mid
    bool check(int mid, vector<int>&stone, int n){
        unordered_set<int>s;
        int prev=0; s.insert(stone[0]);
        
        for(int i=1; i<n; i++){
            if(stone[i]-prev>mid){
                //means i have to jump at stone preceeding current stone
                if(s.find(stone[i-1])!=s.end()){
                    //means already present so not possible
                    return false;
                }
                //else put it in set
                s.insert(stone[i-1]);
                prev=stone[i-1];
                //jumped to stone[i-1]
            }
        }
        prev=stone[n-1];
        s.erase(stone[0]);
        for(int i=n-2; i>=0; i--){
           //now i will be jumping to every one
            //nd evryone should have difference <=mid
            if(s.find(stone[i])==s.end()){ //means we have not jumped ever
                if(prev-stone[i]>mid)return false;
                
                prev=stone[i];
            }
        }
        return true;
    }
    int maxJump(vector<int>& price) {
        int ans=-1, n=price.size();
        int l=0, r=1e9;
        
       //ffffttttt
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid, price, n)==true){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};