class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n =  arr.size();
        set<int>s;
        map<int,int>m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        for(auto it:m){
            cout<<it.second<<" ";
            s.insert(it.second);
        }
        if(s.size()==m.size())return true;
        return false;
    }
};