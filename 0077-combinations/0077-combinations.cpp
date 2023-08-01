class Solution {
    vector<int>v;
    vector<vector<int>>ans;
    private:
    void f(int index, int n, int k){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<=n;i++){
            v.push_back(i);
            f(i+1,n,k);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        f(1,n,k);
        return ans;
    }
};