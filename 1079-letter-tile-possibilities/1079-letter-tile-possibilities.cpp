class Solution {
public:
    void rec(string t, int ind, int &ans){
        ans++;
        for(int i=ind; i<t.size(); i++){
            if(i!=ind && t[i]==t[ind])continue;
            swap(t[i],t[ind]);
            rec(t,ind+1,ans);
        }
    }
    int numTilePossibilities(string t) {
        int ans=-1;
        sort(t.begin(),t.end());
        rec(t,0,ans);
        return ans;
    }
};