class Solution {
public:
    bool check(vector<int>& grades,int allowedgrps){
        int reqgrades=allowedgrps*(allowedgrps+1LL)/2;
        
        int n=grades.size();
        if(reqgrades<=n)return true;
        else return false;
    }
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int l=0, r=grades.size();
        int ans=-1;
        //TTTTTFFFFF
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(grades,mid)==true){
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