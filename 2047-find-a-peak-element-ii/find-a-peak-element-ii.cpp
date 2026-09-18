class Solution {
public:
  
    int findmax(vector<vector<int>>& mat,int col){
        int row = mat.size() ;
        int max = INT_MIN ;
        int index = -1 ;   
   
    for(int i=0 ; i<row ; i++){
        if(mat[i][col]>max){
            max = mat[i][col] ;
            index = i ; 
        }
    }
        return index ;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size() ;
        int col = mat[0].size() ;
        vector<int> ans ;

        int low = 0 ;
        int high = col-1 ;
        int mid ;    

       while(low<=high){
        mid = (low+high)/2 ;
        int maxrow = findmax(mat,mid) ;

        int left = mid-1>=0 ? mat[maxrow][mid-1] : INT_MIN ;
        int right = mid+1<col ? mat[maxrow][mid+1] : INT_MIN ;
     
       if(mat[maxrow][mid]>left && mat[maxrow][mid]>right){
          return {maxrow,mid} ;
       }

      else if(mat[maxrow][mid]<left){
         high = mid-1 ;
      }
       else if(mat[maxrow][mid]<right){
          low = mid+1 ;
       } 
       }
       return {-1,-1} ;
    }
};