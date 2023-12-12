class Solution {
public:
    static bool cmp(vector<int>&t1, vector<int>&t2){
        //sort on basis of end time
        return t1[1]<t2[2];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int timeon[2001]={0};
        sort(tasks.begin(), tasks.end(),[](const auto &t1, const auto &t2){
            return t1[1]<t2[1];
        });
        
        for(auto task: tasks){
            int start=task[0], end=task[1], duration=task[2];
            
            //sub if already done in beginning
            for(int i=start; i<=end; i++){
                if(timeon[i]==1)duration--; //we don't need here
            }
            
            //fill remaining at the end so they might overlap
            for(int i=end; duration>0; i--){
                if(timeon[i]==1)continue;
                else{
                    duration--; timeon[i]=1;
                }
            }
        }
        //check how many are on
        int ans=0;
        for(int i=1; i<=2000; i++){
            if(timeon[i]==1)ans++;
        }return ans;
    }
};