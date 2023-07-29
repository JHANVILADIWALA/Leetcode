class Solution {
public:
    int maxArea(vector<int>& h) {
        // TC : O(N)
        // SC : O(1)
        int n=h.size();
        //taking pointers
        int left=0, right=n-1;
        //final ans
        int ans=0;

        while(left<right){
            //calculating current area
            int w = right-left;
            int ht= min( h[left], h[right] );
            int area= w*ht;

            ans=max(ans,area);
            
            // 3 possibilities
            if(h[left]>h[right])right--; //search for bigger right
            else if(h[left]<h[right])left++; //search for bigger left
            else {
                left++; right--;
            } 
        }
        return ans;
    }
};