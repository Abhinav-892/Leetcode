class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        int product = 1 ;
        int mxproduct = nums[0] ;

    for(int i=0 ; i<n ; i++){
         product *= nums[i] ;
         for(int j=i+1 ; j<n ; j++){
            product *= nums[j] ;
            mxproduct = max(mxproduct,product) ;
         }  
         product = 1 ;
    }

    for(int i=0 ; i<n ; i++){
           mxproduct = max(mxproduct,nums[i]) ;
       }

        return mxproduct ;
    }
};