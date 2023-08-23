class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        
        
        for(auto it:s)mp[it]++;
        for(auto it: mp)pq.push({it.second, it.first});
        
        while(pq.size()>1){
            auto top1= pq.top(); pq.pop();
            auto top2= pq.top(); pq.pop();
            
            ans+= top1.second;
            ans+= top2.second;
            
            top1.first--, top2.first--;
            
            //again push
            if(top1.first>0)pq.push({top1.first, top1.second});
            if(top2.first>0)pq.push({top2.first, top2.second});
        }
        
        if(!pq.empty()){ //means 1 element remains
            if(pq.top().first>1)return "";
            else ans+=pq.top().second;
        }
        return ans;
    }
};