//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        long long sum=1;
        for(long long i=2; i*i<=n; i++){
            //   cout<<"hi";
            if(n%i==0){
                if(i*i!=n)sum = sum + i + n/i;
                else
                sum=sum+i;
            }
        }
        if (sum == n && n != 1)
          return 1;
  
     return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends