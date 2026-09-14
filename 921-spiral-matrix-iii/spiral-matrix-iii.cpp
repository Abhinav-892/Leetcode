class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result ;
        vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}} ;

      int step = 0;
      int index = 0 ;

     result.push_back({rStart,cStart}) ;

     while(result.size()<rows*cols){
        if(index==0 || index==2){
            step++ ;
        }
        for(int i=0 ; i<step ; i++){
            rStart += direction[index][0] ;
            cStart += direction[index][1] ;
 
        if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
            result.push_back({rStart,cStart}) ;
        }
        }
        index = (index+1)%4 ;
     } 
       return result ;
    }
};