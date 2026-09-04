class Solution {
public:
    string reorganizeString(string s) {
        int map[256] = {0} ;
        string ans ;

    for(int i=0 ; i<s.size() ; i++){
        char ch = s[i] ;
        map[ch]++ ;
    } 

    int max_freq = INT_MIN ;
    char mf_char ;

    for(int i='a' ; i<='z' ; i++){
        if(map[i]>max_freq){
            max_freq = map[i] ;
            mf_char = i ;
        }
    }

    int index=0 ;

    if(max_freq>((s.size()+1)/2)){
        return "" ;
    }

    while(max_freq>0){
     s[index] = mf_char ;    
      index = index+2 ;
      max_freq-- ;
    }



     map[mf_char] = 0 ;

    for(int i='a' ; i<='z' ; i++){
        while(map[i]>0){
          index = index<s.size() ? index : 1 ;
          s[index] = i ;
          map[i]-- ;
          index = index+2 ;
        }
    }
      return s ;
    }
};