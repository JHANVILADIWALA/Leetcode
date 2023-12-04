class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        vector<int>v;
        for(int i=0; i<=num.size()-3; i++){
            string temp="";
            temp+=num[i]; temp+=num[i+1]; temp+=num[i+2];
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                int val=stoi(temp);
                v.push_back(val);
            }
        }
        if(v.size()==0)return "";
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        ans=to_string(v[0]);
        if(ans.size()<3)ans='0'+ans;
        if(ans.size()<3)ans='0'+ans;
        return ans;
    }
};