class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        bool present=false; //checks if 1 is present
        
        for(int i=0; i<n; i++){
            if( arr[i]==1 ){
                present=true;
                break;
            }
        }
        
        if( present==false ){
            return 1;
        }
        
        //changing other values to 1
        for(int i=0; i<n; i++){
            if(arr[i]<=0 || arr[i]>n){
                arr[i]=1;
            }
        }
        
        for(int i=0; i<n; i++){
            arr[ (arr[i]-1)%n ]+= n;
        }
        
        for(int i=0; i<n; i++){
            if (arr[i] <= n)
            return i + 1;
        }
        
        return n+1 ;
    }
};