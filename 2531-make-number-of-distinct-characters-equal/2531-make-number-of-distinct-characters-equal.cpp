class Solution {
public:
    void exchange(unordered_map<char,int>&m, int ins, int del){
        m[ins]++; 
        m[del]--;
        if(m[del]==0)m.erase(del);
    }
    bool isItPossible(string s1, string s2) {
        unordered_map<char,int>m1,m2;
        for(auto it:s1)m1[it]++;
        for(auto it:s2)m2[it]++;
        
        for(char c1='a'; c1<='z'; c1++){
            for(char c2='a'; c2<='z'; c2++){
                if(m1.count(c1)==0 || m2.count(c2)==0)continue; //if not available
                
                exchange(m1, c2, c1);
                exchange(m2, c1, c2);
                
                if(m1.size()==m2.size())return true;
                
                exchange(m1, c1, c2);
                exchange(m2, c2, c1);
            }
        }
        return false;
    }
};