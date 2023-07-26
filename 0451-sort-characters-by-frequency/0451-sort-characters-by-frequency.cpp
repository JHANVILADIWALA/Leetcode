class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m; //char , count
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        string ans="";

        vector<pair<int,char>>v;
        for(auto it:m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto it:v ){
           int ckt=it.first;
           char c= it.second;
           for(int i=0;i<ckt;i++)ans+=c;
        }
        return ans;
    }
};