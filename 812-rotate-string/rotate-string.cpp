class Solution {
public:
   
     string shift(string s){
    int n = s.size() ;
    char last = s[n-1] ;
    for(int i=n-1 ; i>0 ; i--){
        s[i] = s[i-1] ;
    }
    s[0] = last ;
     return s ;
   }

    bool rotateString(string s, string goal) {
         
      int n = s.size() ;   
      string ans = shift(s) ;   

        for(int i=0 ; i<n ; i++){
            
            if(ans == goal){
                return true ;
            }
            else{
               ans = shift(ans) ;
            }
        }
        return false ;
    }
};