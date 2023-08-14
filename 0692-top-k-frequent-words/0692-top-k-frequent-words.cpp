#define psi pair<int, string>
class Solution {
public:
    static bool cmp(const psi&a, const psi&b){
        if(a.first==b.first)return a.second<b.second;
        else{
            return a.first>b.first;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string>ans;
        unordered_map<string,int>m;
        for(int i=0; i<words.size(); i++)m[words[i]]++;
        
        vector<psi>v;
        for(auto it:m){
            v.push_back({it.second,it.first}); //freq,string
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
        return ans;
        
    }
};