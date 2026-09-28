class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>pv(26,0) ;
    vector<int>sv(26,0) ;
    int ps = p.size() ;
    int ss = s.size() ;
    int left = 0 ;
    int right = 0 ;
    vector<int> ans ;

    if(ps>ss){
        return ans ;
    }

     while(right<ps){
     pv[p[right]-'a']++ ;
     sv[s[right]-'a']++ ;
     right++ ;
    }
 
    right-- ;

    while(right<ss){
        if(pv==sv){
           ans.push_back(left) ; 
        }
        right++ ;
        if(right<ss){
            sv[s[right]-'a']++ ;
        }
        sv[s[left]-'a']-- ;
        left++ ;
    }  
       return ans ;
    }
};