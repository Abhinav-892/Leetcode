class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ;
        vector<int> pv(26,0) ;
        vector<int> sv(26,0) ;

        int ps = p.size() ;
        int ss = s.size() ;

        if(ps>ss){
            return ans ;
        }

        int left = 0 ;
        int right = 0 ;

       while(right<ps){
        pv[p[right]-'a'] += 1 ;
        sv[s[right]-'a'] += 1 ;
         right++ ; 
       }    

       right -= 1 ;

       while(right<ss){
        if(pv==sv){
            ans.push_back(left) ;
        }
        right += 1 ;
        if(right!=ss){
            sv[s[right]-'a'] += 1 ;
        }
            sv[s[left]-'a'] -= 1 ;
            left+=1 ;
       }
        return ans ; 
    }
};