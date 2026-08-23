class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int s = 0;
        int e = n-1 ;
        int FA = 0 ;  


    while((e-s)>=0){
        int st = height[s] ;
        int end = height[e] ;
        int area1 = 0 ;
        int area2 = 0 ;
        
        if(height[e]>=height[s]){
          area1 = height[s]*(e-s) ;
        } 

        if(height[s]>=height[e]){
          area2 = height[e]*(e-s) ;
        }  

        FA = max(FA,max(area1,area2)) ;

       if(height[s]>height[e]){
           e-- ;
       }

       else if(height[e]>=height[s]){
           s++ ;
       }
    }   
      return FA ;
    }
};