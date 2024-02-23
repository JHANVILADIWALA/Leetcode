class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //pointers
        int left=0;
        int right=n-1;

        //max values
        int lmax=0,rmax=0;

        //water
        int water=0;

        //while loop
        while(left<=right){
            if(lmax<=rmax){
              water+=max(0,lmax-height[left]);
              lmax=max(lmax,height[left]);
              left++;
            }
            else{
              water+=max(0,rmax-height[right]);
              rmax=max(rmax,height[right]);
              right--;
            }
        }
        return water;
    }
};