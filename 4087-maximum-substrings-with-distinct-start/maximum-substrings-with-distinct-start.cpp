class Solution {
public:
    int maxDistinct(string s) {
        int count = 0 ;
        unordered_map<char,int> mapped ;
         char start = 'a' ;

        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i] ;
            if(mapped.find(ch)==mapped.end()){
                mapped[ch] = start ;
                start ;    
            }
        }  
      return mapped.size() ;
    }
};