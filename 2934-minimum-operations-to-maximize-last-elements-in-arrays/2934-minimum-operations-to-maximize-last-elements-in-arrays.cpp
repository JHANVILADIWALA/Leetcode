class Solution {
public:
    int fn(vector<int>& nums1, vector<int>& nums2){
        int opr=0;
        int n=nums1.size();
        for(int i=0; i<n-1; i++){
            if(nums1[i]>nums1[n-1] || nums2[i]>nums2[n-1]){//anybody violates
                opr++;
                if(nums2[i]>nums1[n-1] || nums1[i]>nums2[n-1]){
                    return -1;
                }
            }
        }
        return opr;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int k1=fn(nums1,nums2);
        int n=nums1.size();
        swap(nums1[n-1],nums2[n-1]);
        int k2=fn(nums1,nums2);
        cout<<k1<<" "<<k2<<endl;
        return min(k1,k2+1);
    }
};