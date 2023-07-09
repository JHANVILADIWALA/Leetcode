class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0; i<nums.size()-1; i++){
            v.push_back(nums[i+1]-nums[i]);
        }
        int ans=0, ckt=0;
           if(n==2){
            if( (nums[0] - nums[1]) ==-1 )return 2;
            return -1;
        }
        if(n==3){
            if(  (nums[1]-nums[0])==1 ||  (nums[1]-nums[2])==-1 ){
                if(nums[0]==nums[2])return 3;
                    
                else return 2;
            }
            else return -1;
        }
        bool flg=false;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
            if(v[i]==1){
                flg=true;
                ckt++;
                for(int j=i+1; j<v.size(); j++){
                    if(v[j]==-v[j-1])ckt++;
                    else{
                        ans=max(ans,ckt);
                        ckt=0;
                        break;
                    }
                }
                ans=max(ans,ckt);
                        ckt=0;
            }
        }
        
       if(flg==true) ans=max(ans,ckt);
        
        if(ans==0)return -1;
        else return ans+1;
    }
};