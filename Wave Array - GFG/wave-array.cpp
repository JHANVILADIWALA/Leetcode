//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        vector<int>a;
        vector<int>b;
        for(int i=0; i<arr.size(); i++){
            if(i&1)a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }
        vector<int>ans;
        for(int i=0; i<min(a.size(),b.size()); i++){
            ans.push_back(a[i]);
            ans.push_back(b[i]);
        }
        ans.push_back(b[b.size()-1]);
        for(int i=0; i<arr.size(); i++){
            arr[i]=ans[i];
        }
        return;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        sort(a.begin(),a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
// } Driver Code Ends