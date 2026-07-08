class Solution {
public:

   int solveUsingRecursion(vector<int>& nums,int index){
    if(index>=nums.size()){
        return 0 ;
    }
   int include = nums[index] + solveUsingRecursion(nums,index+2) ;
   int exclude = 0 + solveUsingRecursion(nums,index+1) ;

   int ans = max(include,exclude) ;
      return ans ;
   }

  //1d DP (as here only one parameter changes that is index)
  //Method-1 Rec + Memorisation - Top Down Solution

  int solveUsingMem(vector<int>& nums,int index,vector<int>& dp){
    if(index>=nums.size()){
        return 0 ;
    }

   if(dp[index] != -1){
    return dp[index] ;
   }

   int include = nums[index] + solveUsingMem(nums,index+2,dp) ;
   int exclude = 0 + solveUsingMem(nums,index+1,dp) ;
   int ans = max(include,exclude) ;
   
   dp[index] = ans ;

      return ans ;
  }





    int rob(vector<int>& nums) {
        int index = 0 ;

    //    int ans = solveUsingRecursion(nums,index) ; 
      
    //Method1 - Top Down
    int n = nums.size() ;
    vector<int> dp(n+1,-1) ; 
    int ans = solveUsingMem(nums,index,dp) ; 
      
       return ans ;
    }
};