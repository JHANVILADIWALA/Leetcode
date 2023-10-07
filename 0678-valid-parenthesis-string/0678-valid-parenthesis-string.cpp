class Solution {
public:
    bool checkValidString(string s) {
        //we have to take 2 stacks
        stack<int>star;
        stack<int>par;
        
        //balancing close brackets
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*')star.push(i);
            if(s[i]=='(')par.push(i);
            if(s[i]==')'){
                if(!par.empty())par.pop();
                else if(!star.empty())star.pop();
                else return false;
            }
        }
        
        //balancing open brackets
        while(!par.empty()){
            if(star.empty())return false;
            // int leftbrack=par.top();
            // int rightstar=star.top();
            else if(star.top()>par.top()){
                star.pop(); par.pop();
            }
            else return false;
        }
        return true;
        
    }
};