class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        multiset<int>s;
        for(int i=0; i<h.size()-1; i++){
            if(h[i+1]>h[i]){
                s.insert(h[i+1]-h[i]);
                if(s.size()>l){
                    b-=*s.begin();
                    s.erase(s.begin());
                    if(b<0)return i;
                }
            }
        }
        return h.size()-1;
    }
};