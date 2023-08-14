class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        
        priority_queue<int>pq;
        for(int i=0; i<piles.size(); i++)pq.push(piles[i]);
        
        while(k--){
            int x=pq.top(); pq.pop();
            x-=x/2;
            pq.push(x);
        }
        
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};