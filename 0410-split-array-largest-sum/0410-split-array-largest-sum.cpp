# define ll int
class Solution {
public:
    bool check(int maxsum, vector<int>&a,int k){
	int ckt=1,sum=0;
	for(int i=0; i<a.size(); i++){
		if(a[i]>maxsum)return false;
		if(sum+a[i]<=maxsum){
			sum+=a[i];
		}
		else{
			sum=a[i];
			ckt++;
		}
	}
	if(ckt>k)return false;
	else return true;
}
    int splitArray(vector<int>& v, int k) {
        int totalsum=0;
        for(auto it: v)totalsum+=it;
       int l=1, r=totalsum;
       int ans=totalsum;
   
   while(l<=r){
   	ll mid=(l+r)/2;
   	if(check(mid,v,k)){
   		 ans=mid;
   		 r=mid-1;
	   }
	   else l=mid+1;
   }
   return ans;
    }
};