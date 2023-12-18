class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum=0;
        int maxi=INT_MIN;
        for(auto it: m){
            sum+=it.second;
            maxi=max(sum, maxi);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */