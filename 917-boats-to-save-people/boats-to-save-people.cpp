class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       
        sort(people.begin(),people.end()) ; 
       
        int n = people.size() ;
        int i = 0 ;
        int j = n-1 ;
        int ans = 0 ;

     while(i<=j){

    if(people[i]==limit){
        ans++ ;
        i++ ;
    } 
    else if(people[j]==limit){
        ans++ ;
        j-- ;
    }

    else if(i==j){
        ans++ ;
        break ;
    }

    else{
        int sum = people[i] + people[j] ;
        if(sum<=limit){
            ans++ ;
              i++ ;
               j-- ; 
        }
        else{
            ans++ ;
            j-- ;
        } 
    } 
 }
     return ans ;
    }
};