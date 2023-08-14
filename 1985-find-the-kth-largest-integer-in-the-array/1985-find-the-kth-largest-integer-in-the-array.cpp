class Solution {
public:
    static bool cmp(string&a, string&b){
        
        //returns whether a should come before b or not
        
        if(a.size()==b.size())return a>b; //if size same then return lexicographically greater
        else return a.size()>b.size(); //else return greater length string
    }
    string kthLargestNumber(vector<string>& nums, int k) { 
        //sort the vector in decreasing order of numbers
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};