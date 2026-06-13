string ordercopy ;

class Solution {
public:

static bool comp(char ch1 , char ch2){
    return (ordercopy.find(ch1) < ordercopy.find(ch2)) ;
}

    string customSortString(string order, string s) {

 ordercopy = order ;

sort(s.begin(),s.end(),comp) ;

return s ;

    }
};