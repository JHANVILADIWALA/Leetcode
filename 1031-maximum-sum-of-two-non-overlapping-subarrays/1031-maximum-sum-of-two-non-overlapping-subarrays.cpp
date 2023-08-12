class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int len1, int len2) {
        int ans=0;
        int n=nums.size(), sum=0;
        
        //prefix vector
        vector<int>pref(n,0);
        for(int i=0; i<n; i++){
            sum+=nums[i];
            pref[i]=sum;
        }
        
        for(int i=0; i<n; i++){
            int l1=i, r1=i+len1-1;
            if(r1>=n)break;
            int sum1= pref[r1];
            if(l1>0)sum1-=pref[l1-1]; //if its not zero then it might have ones before that subarray
            
            for(int j=0; j<n; j++){
                int l2=j, r2=j+len2-1;
                if(r2>=n)break;
                int sum2=pref[r2];
                if(l2>0)sum2-=pref[l2-1];
                
                //overlapping conditions satisfied-> continue
                if (l2 >= l1 && l2 <= r1)continue;
                if (r2 >= l1 && r2 <= r1)continue;
                if (l1 >= l2 && l1 <= r2)continue;
                if (r1 >= l2 && r1 <= r2)continue;
                
                //means its not overlapping
                ans=max(ans, sum1+sum2 );
            }
        }
        return ans;
    }
};