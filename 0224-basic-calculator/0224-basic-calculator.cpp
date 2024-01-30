class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        
        int num=0;
        int ans=0;
        int sign=1;
        
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0'); //number making
            }
            else if(s[i]=='+'){
                //number already made
                ans += num*sign;
                num=0;
                sign=1;
            }
            else if(s[i]=='-'){
                //number already made
                ans += num*sign;
                num=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                num=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans+= num*sign; //bracket k andr ka result
                num=0;
                
                int stsign=st.top(); st.pop();
                int lastres=st.top(); st.pop();
                
                ans*=stsign;
                ans+=lastres;
            }
        }
        ans += num*sign;
        return ans;
    }
};