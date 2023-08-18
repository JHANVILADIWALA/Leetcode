class Solution {
public:
    int ans=0;
    void fn(int ind, vector<string>& words , map<char,int>sc , map<char,int>lt ,int maxs){
        if(ind==words.size()){  //base case
            ans=max(ans,maxs);
            return ;
        }
        
        //can pick or not
        int flg=0;
        
        map<char,int>freq; // putting freq of letters of that word in map
        for(auto it: words[ind])freq[it]++;
        
        //if sufficinent letters not there then can't pick up
        for(auto it: words[ind]){
            if(lt[it]<freq[it])flg=1;
        }
        
        if(flg==0){ //can pick
            //create new map and delete leters already occured from it
            map<char,int>dummy=lt;
            for(auto it:words[ind] )dummy[it]--;
            
            //adding score 
            int curscore=0;
            for(auto it:words[ind]){
                curscore+= sc[it];
            }
            fn(ind+1, words, sc, dummy, curscore+maxs );
        }
        fn(ind+1,words,sc,lt,maxs);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>sc, lt;
        for(auto it : letters)lt[it]++; //letters in map
        for(int i=0; i<26; i++){        //scores in map
            sc[i+'a']=score[i];
        }
        fn(0,words,sc,lt,0);
        return ans;
    }
};