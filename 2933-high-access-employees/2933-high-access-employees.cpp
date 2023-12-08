class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        unordered_map<string,vector<string>>m;
        sort(at.begin(), at.end());
        for(auto it: at){
            m[it[0]].push_back(it[1]);
        }
        vector<string>ans;   
        for(auto it:m){
            if(it.second.size()>=3){
                for(auto xx: it.second)cout<<xx<<endl;
                bool flg=false;
                for(int i=0; i<=it.second.size()-3; i++){
                    //first
                    int a;
                    string temp1=""; temp1+=it.second[i];
                    // temp1+=it.second[i][0]; temp1+=it.second[i][1]; temp1+=it.second[i][2]; temp1+=it.second[i][3];
                    a=stoi(temp1);
                    
                    //third
                    int b;
                    string temp2=""; temp2+=it.second[i+2];
                    // temp2+=it.second[i+2][1]; temp2+=it.second[i+2][2]; temp2+=it.second[i+2][3];
                    b=stoi(temp2);
                    
                    if(b<=a+99 )flg=true;
                }
                if(flg==true)ans.push_back(it.first);
            }
        }
        return ans;
    }
};