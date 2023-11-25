class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(), m=l.size();
        vector<bool>ans;
        for(int i=0; i<m; i++){
            bool flg=true;
            int s=l[i], e=r[i];
            vector<int>v=nums;
            sort(v.begin()+s, v.begin()+e+1);
            int d=v[s+1]-v[s];
            for(int j=s+1; j<e; j++){
                if(v[j+1]-v[j]!=d){flg=false; break;}
            }
            ans.push_back(flg);
        }
        return ans;
    }
};