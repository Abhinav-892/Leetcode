class Solution {
public:
    int subtractProductAndSum(int n) {
        int mult = 1 ;
        int add = 0 ; 
        int original = n ;  

       while(n>0){
        int digit = n%10 ;
        mult = mult*digit ;
        n = n/10 ;
       }    

     n = original ;

     while(n>0){
        int digit = n%10 ;
        add = add + digit ;
        n = n/10 ;
     }  

    int ans = mult-add ;
    return ans ;
    }
};