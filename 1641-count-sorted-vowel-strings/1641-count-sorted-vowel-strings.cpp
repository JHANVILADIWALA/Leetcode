class Solution {
public:
    int countVowelStrings(int n) {
       //method 1
       vector<int>v(5,1); //a e i o u
        for(int i=2;i<=n;i++){
            for(int j=3; j>=0;j--){ //traverse on vector except last block
                v[j]+=v[j+1];
            }
        }
        //finding sum of all
        int ans=0;
        for(int i=0;i<5;i++)ans+=v[i];
        return ans;
    }
};