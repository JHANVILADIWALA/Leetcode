class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans;
        stack<int>s;
        int n=t.size();
        
        for(int i=n-1; i>=0; i--){
            if(s.empty()){
                s.push(i);  ans.push_back(0);
            }
            else{
                while(!s.empty() && t[s.top()]<=t[i]){
                    s.pop();
                }
                if(s.empty()){
                   s.push(i);  ans.push_back(0);
                }
                else{
                   ans.push_back(s.top()-i); 
                   s.push(i);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};