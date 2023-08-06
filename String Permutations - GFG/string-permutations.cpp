//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void rec(string s, int ind, vector<string>&ans){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            swap(s[i],s[ind]);
            rec(s,ind+1,ans);
            swap(s[i],s[ind]);
        }
    }
    vector<string> permutation(string s)
    {
        vector<string>ans;
        // string temp=s;
        rec(s,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends