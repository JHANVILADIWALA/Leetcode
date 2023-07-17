//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		     queue<char>q;
		     vector<int>f(26,0);
		     string ans=""; //string to be returned
		     
		     for(auto it:s){ //traversing on given string
		     
		         f[it-'a']++; //keeping ckt of character in vector
		         
		         if( f[it-'a']==1 ){
		             q.push(it);
		         }
		         
		         while(q.size() && f[q.front()-'a']>1)q.pop();
		         
		         if(q.size()==0)ans+='#';
		         else ans+=q.front();
		     }
		     return ans;
		     
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends