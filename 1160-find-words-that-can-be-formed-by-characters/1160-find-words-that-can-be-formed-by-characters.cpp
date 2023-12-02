class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>m;
        for(auto it:chars)m[it]++;
        int ans=0;
        for(int i=0; i<words.size(); i++){
            bool flg=true;
            unordered_map<char,int>y=m;
            for(auto it:words[i]){
                if(y[it]>0)y[it]--;
                else flg=false;
            }
            if(flg==true){ 
                cout<<words[i]<<" "<<words[i].size()<<endl;
                ans+=words[i].size();}
        }
        return ans;
    }
};