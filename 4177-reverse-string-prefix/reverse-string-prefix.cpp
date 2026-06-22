class Solution {
public:
    string reversePrefix(string s, int k) {
                int n = s.size() ;
        int start = 0 ;
        int e = k-1 ;

   
    while(start<=e){
       swap(s[start],s[e]) ;
       start++ ;
       e--; 
     }
          return s ;
    }
};