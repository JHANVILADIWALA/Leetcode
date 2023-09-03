class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ckt=1;
        string temp=a;
        while(temp.size()<b.size()){
            temp+=a; ckt++;
        }
        if(temp.find(b)!=string::npos)return ckt;
        
        temp+=a; ckt++;
        if(temp.find(b)!=string::npos)return ckt;
        
        return -1;
    }
};