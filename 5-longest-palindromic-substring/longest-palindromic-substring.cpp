class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0 ;
        int len = 0;
        int start ;
        int i ;
        int j ;


     for(int centre=0 ; centre<s.size(); centre++){
          i = centre ;
          j = centre ;

      while(i>=0 && j<s.size()){
        if(s[i]==s[j]){
            i-- ;
            j++ ;
        }
        else{
            break ;
        }
      }
        maxLength = j-i-1 ;

       if(maxLength>len){
          len = maxLength ;
          start = i+1 ;
       }
     }

       for(int centre=0 ; centre<s.size()-1 ; centre++){
         i = centre ;
         j = centre+1 ;

      while(i>=0 && j<s.size()){
        if(s[i]==s[j]){
            i-- ;
            j++ ;
        }
        else{
            break ;
        }
      }
        maxLength = j-i-1 ;

       if(maxLength>len){
          len = maxLength ;
          start = i+1 ;
       }
     }     
        
     return s.substr(start,len) ;

    }
};