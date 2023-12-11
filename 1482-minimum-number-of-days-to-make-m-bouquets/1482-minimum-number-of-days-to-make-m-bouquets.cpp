class Solution {
public:
    bool check(int availdays, vector<int>& bd, int m, int k){
        //check whether it is possible to make m bouquets in availdays
        int bouq=0, flower=0;
        for(auto it: bd){
            if(it<=availdays)flower++;
            else flower=0;
            
            if(flower==k){bouq++; flower=0;}
        }
        if(bouq>=m)return true;
        else return false;
        
    }
    int minDays(vector<int>& bd, int m, int k) {
        long long n=bd.size();
        long long v=(long long)m*(long long)k;
        if(n<v)return -1;
        
        long long l=1, r=1e9;
        int ans=r;
        
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,bd,m,k)==true){
                ans=mid; r=mid-1;
            }
            else{
                l=mid+1;
            }
        }return ans;
    }
};