class Solution {
public:
    bool fn(int mid, vector<int>& h, int b, int l){
        vector<int>diff;
        for(int i=0; i<mid; i++){
            if(h[i]<h[i+1])diff.push_back(h[i+1]-h[i]);
        }
        sort(diff.begin(), diff.end());
        
        bool flg=true;
        for(auto it: diff){
            if(b>=it)b-=it;
            else if(l>0)l--;
            else{
                flg=false;
                break;
            }
        }
        return flg;
    }
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n=h.size();
        int left=-1, right=n;
        while(right-left>1){
            int mid= (left+right+1)/2;
            if(fn(mid, h, b, l)==false)right=mid;
            else left=mid;
        }
        return left;
    }
};