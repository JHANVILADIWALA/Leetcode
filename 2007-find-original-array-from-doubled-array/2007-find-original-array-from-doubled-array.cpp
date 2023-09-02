    class Solution {
    public:
        vector<int> findOriginalArray(vector<int>& v) {
           sort(v.begin(), v.end());
           vector<int>ans; //
           if(v.size()&1)return {};
           // 0 1 3 6->v
           // 0 1 3 6->set
           multiset<int>s;
            int countofzeroes=0;
            for(auto it: v){
                if(it!=0)s.insert(it);
                if(it==0)countofzeroes++;
            }
            if(countofzeroes&1)return {};
            
            for(int i=0; i<countofzeroes/2; i++){
                ans.push_back(0);
            }
            for(int i=0; i<v.size(); i++){
                if(s.find(v[i])!=s.end() && s.find(2*v[i])!=s.end() && s.find(2*v[i])!=s.find(v[i])){
                    cout<<v[i]<<" "<<2*v[i]<<endl;
                    ans.push_back(v[i]);
                    s.erase(s.find(v[i])); 
                    s.erase(s.find(2*v[i]));
                }
            }
                
            
        int n=s.size();
            if(n!=0)return {};
            return ans;
        }
    };