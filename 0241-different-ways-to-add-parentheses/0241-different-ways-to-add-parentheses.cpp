class Solution {
public:
    int perform(int x, int y, char op){
        if(op=='+')return x+y;
        if(op=='*')return x*y;
        if(op=='-')return x-y;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int>ans;
        bool ispurenumber=true;
        
        for(int i=0; i<exp.size(); i++){
            if(!isdigit(exp[i])){
                ispurenumber=false;
                
                vector<int>left=diffWaysToCompute(exp.substr(0,i)); //left part
                vector<int>right=diffWaysToCompute(exp.substr(i+1)); //right part
                
                for(auto x:left){
                    for(auto y:right){
                        int val= perform(x,y,exp[i]);
                        ans.push_back(val);
                    }
                }
            }
            
        }
        
        if(ispurenumber==true)ans.push_back(stoi(exp)); //as it is
        return ans;
    }
};