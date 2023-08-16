class Solution {
public:
    int minAddToMakeValid(string s) {
        int ckt=0;
        stack<char>stack;
        for(int i=0;i<s.size();i++){
           if(!stack.empty()){
              if(stack.top()=='('&&s[i]==')'){
                 stack.pop();
              }
              else stack.push(s[i]);
           }
           else{
               stack.push(s[i]);
           }
        }  
        ckt+=stack.size();
        return ckt;
    }
};