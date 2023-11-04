class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=0, r=0;
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        if(left.size()>0){
            int ln=left.size();
            l=left[ln-1];
        }
        if(right.size()>0){
            int rn=right.size();
            r=n-right[0];
        }
        return max(l,r);
    }
};