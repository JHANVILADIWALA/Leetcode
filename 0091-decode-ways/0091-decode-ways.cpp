class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0)return 0; //no letter -> no way
        
        // therefore length>0
        if(s[0]=='0')return 0; // 0 can be second digit only of a number
        
        if(s.size()==1)return 1; //only single way possible
        
        int val1=1; //last second
        int val2=1; //last
        // val1 val2
        for(int i=1; i<s.size(); i++){
            int d1 = s[i]-'0'; //single digit
            int d2 = (s[i-1]-'0')*10 + d1; //double digit
            
            int currans=0;
            
            if(d1>=1)currans+=val2;
            if(d2>=10 && d2<=26)currans+=val1;
            
            //new values
            val1=val2;
            val2=currans;
        }
        return val2;
    }
};