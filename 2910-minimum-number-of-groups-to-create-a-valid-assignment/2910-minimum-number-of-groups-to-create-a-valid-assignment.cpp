class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it:nums)m[it]++;
        vector<int>v;
        for(auto it:m){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        
        int ans=INT_MAX;
        
        for(int i=1; i<=v[0]; i++){
            int a=i, b=i+1, num=0;
            bool notpossible=false;
            
            //check whether this is possible
            for(int i=0; i<v.size(); i++){
                int cur=v[i];
                int mn=INT_MAX, ckt=0;
                
                while(cur>=0){
                    if(cur%a==0)mn=ckt+cur/a;
                    cur-=b; ckt++;
                }
                if(mn==INT_MAX){ 
                    notpossible=true; break;
                }
                num+=mn; //add current count
            }
            if(!notpossible){
                ans=min(ans, num);
            }
            
        }
        return ans;
    }
};