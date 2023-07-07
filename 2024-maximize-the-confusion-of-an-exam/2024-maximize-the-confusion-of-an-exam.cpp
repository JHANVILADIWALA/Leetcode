class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0 ;
       
        int ans=1;
        int ckt=0;
        
        int n=s.size();
         
        //counting how many 'Fs' to change
        for(int j=0; j<n; j++){
            
            //increase ckt on encounter of F
            if(s[j]=='F')ckt++;     
            
            // move left pointer to right till we get ckt in range
            while(ckt>k){
                //when we encounter F then only we can reduce ckt
                if(s[i]=='F'){
                    ckt--; 
                }
                i++;
            }
            ans = max(ans, j-i+1);
        }
               i=0,ckt=0;
        //do the same procedure to delete Ts
        for(int j=0; j<n; j++){
            
            //increase ckt on encounter of T
            if(s[j]=='T')ckt++;     
            
            // move left pointer to right till we get ckt in range
            while(ckt>k){
                //when we encounter T then only we can reduce ckt
                if(s[i]=='T'){
                    ckt--; 
                }
                i++;
            } 
            //now ckt is in range
            ans = max( ans, j-i+1 ); 
        }
     
        return ans;
    }
};