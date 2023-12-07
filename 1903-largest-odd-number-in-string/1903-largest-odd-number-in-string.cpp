class Solution {
public:
    string largestOddNumber(string num) {
        int ind=-1;
        for(int i=0; i<num.size(); i++){
            string temp=""; temp+=num[i];
            int n=stoi(temp);
            if(n&1)ind=i;
        }
        if(ind==-1)return "";
        return num.substr(0,ind+1);
    }
};
