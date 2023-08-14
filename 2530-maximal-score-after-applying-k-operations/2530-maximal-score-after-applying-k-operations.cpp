class Solution {
public:
    long long maxKelements(vector<int>& piles, int k) {
        
        long long sum=0;
        
        priority_queue<int>pq;
        for(int i=0; i<piles.size(); i++)pq.push(piles[i]); 
            
        while(k-- ){
            int x=pq.top(); pq.pop();
            sum+=x;
            if ((x + 2) / 3)
            pq.push((x + 2) / 3);
        }
       
        return sum;
    }
};