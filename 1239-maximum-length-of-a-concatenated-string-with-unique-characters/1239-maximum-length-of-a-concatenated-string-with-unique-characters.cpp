class Solution {
public:
    int fn(int i, vector<string>& arr, unordered_map<char,int>m){
        if(i==arr.size()){
            return 0;
        }
        
        //check whether u can or not
        int flg=0;
        for(auto it: arr[i]){
            if(m.find(it)!=m.end())flg=1; //already found so can't pick
        }
        set<char>s;
        for(auto it: arr[i]){
                s.insert(it);
            }
        if(flg==0 && s.size()==arr[i].size()){
            //means not found already
            //pick
            unordered_map<char,int>temp=m;
            for(auto it: arr[i]){
                temp[it]++;
            }
            int pick=arr[i].size()+fn(i+1, arr, temp);
            
            //not pick
            int notpick=fn(i+1, arr, m);
            return max(pick, notpick);
        }
        //not picking
        return fn(i+1, arr, m);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int>m;
        return fn(0, arr, m);
    }
};