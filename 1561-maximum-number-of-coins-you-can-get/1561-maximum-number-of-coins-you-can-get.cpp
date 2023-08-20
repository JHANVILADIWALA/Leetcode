class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        reverse(piles.begin(), piles.end());
        int sum=0;
        int ckt=piles.size()/3;
        
        for(int i=1; i<piles.size(); i=i+2){
            sum+=piles[i];
            ckt--;
            if(ckt==0)break;
        }
        return sum;
    }
};