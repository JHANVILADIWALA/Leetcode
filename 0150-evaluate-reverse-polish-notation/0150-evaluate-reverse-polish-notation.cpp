class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto it: tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int b=(s.top()); s.pop();
                int a=(s.top()); s.pop();
                char opr=it[0];
                int c;
                if(opr=='+')c=a+b;
                if(opr=='-')c=a-b;
                if(opr=='*')c=a*b;
                if(opr=='/')c=a/b;
                
                s.push(c);
            }
            else{
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};