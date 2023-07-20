class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>s;
        
        for(int i=0; i<n; i++){
            if(s.empty() || a[i]>0){
                s.push(a[i]); //alwys add the pos ones
            }
            else{ //means negative
                while(!s.empty() && s.top()>0 && s.top()<abs(a[i])){
                    s.pop(); //pop till neg is found or greater number or equal is found
                }
                if( !s.empty() && s.top()==abs(a[i])){ //equal
                    s.pop();
                }
                else{
                    if(s.empty() || s.top()<0 ){ //stack empty ot found negative
                        s.push(a[i]);
                    }
                }
            }
        }
        vector<int>ans(s.size(),0);
        int size= s.size()-1;
        while(!s.empty()){
            ans[size--]=s.top();
            s.pop();
        }
        return ans;
        
    }
};