class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a); pq.push(b); pq.push(c);
        int ckt=0; 
        
        while(pq.size()>=2){
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
            x--; y--; ckt++;
            if(x==0 && y!=0)pq.push(y);
            else if(x!=0 && y==0)pq.push(x);
            else if(x!=0 && y!=0){
                pq.push(x); pq.push(y);
            }
        }
        return ckt;
    }
};