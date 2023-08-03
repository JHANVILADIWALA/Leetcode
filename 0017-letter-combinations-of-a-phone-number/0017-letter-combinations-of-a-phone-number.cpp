class Solution {
public:
    void rec(string d,vector<string>&button, vector<string>&ans, string& temp, int ind){
        //base condition
        if(ind==d.size()){
            ans.push_back(temp);
            return;
        }
        
        string val=button[d[ind]-'0']; 
        for(int i=0; i<val.size(); i++){
            temp.push_back(val[i]);
            rec(d,button,ans,temp,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        if(d.empty())return {};
        
        vector<string>button={"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string temp;
        rec(d,button,ans,temp,0);
        return ans;
        
    }
};