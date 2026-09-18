class Solution {
public:

    bool isvalid(vector<int>& piles, int h,int mid){
       long long actualhour = 0 ;
       for(int x:piles){
          actualhour += x/mid ;
          if(x%mid!=0){
             actualhour++ ;
          }
       }
       return actualhour<=h ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ;
        int s = 1 ;
        int e = INT_MIN ;

      for(int i=0 ; i<n ; i++){
        e = max(e,piles[i]) ;
      }

        int ans = -1 ;
    
    while(s<=e){
        int mid = (s+e)/2 ;
        
        if(isvalid(piles,h,mid)){
         ans = mid ;
         e = mid-1 ;
        }
        else{
            s = mid+1 ;
        }
    } 
     return ans ;
    }
};