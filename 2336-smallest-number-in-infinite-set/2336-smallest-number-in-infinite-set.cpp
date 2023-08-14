class SmallestInfiniteSet {
public:
    map<int,int>m;
    SmallestInfiniteSet() {
        for(int i=1; i<1002; i++)m[i]++;
    }
    
    int popSmallest() {
        //erasing the smallest value
        int val=m.begin()->first;
        m.erase(val);
        return val;
    }
    
    void addBack(int num) {
        m[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */