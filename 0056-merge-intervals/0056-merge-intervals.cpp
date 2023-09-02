class Solution {
public:
    // static int cmp(vector<int> a, vector<int> b){
    //     if(a[0]==b[0])return a[1]<b[1];
    //     else return a[0]<b[0];
    // }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>ans;
        sort(v.begin(), v.end());
        int start= v[0][0], end= v[0][1];
        int i=1;
        bool ended=false;
        int n = v.size();
        for(int i=1; i<v.size(); i++){
            cout<<start<<" "<<end<<endl;
            if(end>=v[i][0]){
                // if(i==v.size()-1)ended=false;
                end=max(end,v[i][1]);
            }
            else{
                vector<int>temp;
                temp.push_back(start), temp.push_back(end);
                ans.push_back(temp);
                 if(i==v.size()-1)ended=true;
                start= v[i][0];
                end = v[i][1];
            }
        }
        cout<<start<<" "<<end<<endl;

        // if(ended==false){
             vector<int>temp;
                temp.push_back(start), temp.push_back(end);
                ans.push_back(temp);
        // }
             
                
        return ans;
    }
};