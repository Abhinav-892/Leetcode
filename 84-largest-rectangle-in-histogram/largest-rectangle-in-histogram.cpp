class Solution {
public:

   void nextSmallest(vector<int>& heights,vector<int>& nextAns){
   stack<int> st ;
   st.push(-1) ;
   int n = heights.size() ;

   for(int i=n-1 ; i>=0 ; i--){
    int element = heights[i] ;

   while(st.top()!=-1 && heights[st.top()]>=element){
       st.pop() ;
   }
    nextAns.push_back(st.top()) ;
    st.push(i) ; 
   }
}

  void prevSmallest(vector<int>& heights,vector<int>& prevAns){
    stack<int> st ;
    st.push(-1) ;
    int n = heights.size() ;

    for(int i=0 ; i<n ; i++){
        int element = heights[i] ;

    while(st.top()!=-1 && heights[st.top()]>=element){    // vaha index insert kiya hai stack mein   
        st.pop() ;                                        // not val.
    }
      prevAns.push_back(st.top()) ;
      st.push(i) ;
    }
  } 

    int largestRectangleArea(vector<int>& heights) {
    vector<int> nextAns ;
    vector<int> prevAns ;

    nextSmallest(heights,nextAns) ;
    reverse(nextAns.begin(),nextAns.end()) ;

    for(int i=0 ; i<nextAns.size() ; i++){
        if(nextAns[i] == -1){                // corner case maybe bhul jaunga
            nextAns[i] = nextAns.size() ;
        }
    }

    prevSmallest(heights,prevAns) ;

     int maxArea = INT_MIN ;
     for(int i=0 ; i<nextAns.size() ; i++){
        int width = nextAns[i]-prevAns[i]-1 ;  //
        int height = heights[i] ;
        int currArea = width*height ;
        maxArea = max(maxArea,currArea) ;
     }
      return maxArea ;
    }
};