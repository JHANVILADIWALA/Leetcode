class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda=[](int &a, int &b){
            int c1=__builtin_popcount(a);
            int c2=__builtin_popcount(b);
            
            if(c1==c2)return a<b;
            else return c1<c2;
        };
        
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};