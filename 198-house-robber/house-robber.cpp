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


//Method-2 Tabulation/Bottom-Up Approach

int solveUsingTabulation(vector<int>& nums){

//Step1: dp array create intialise
   int n = nums.size() ;
   vector<int> dp(n+1,-1) ; 

 //Step2: analyse base case and fill dp array
  dp[n] = 0 ;

//Step3: reverse the flow,loop,copy paste
 for(int i=n-1 ; i>=0 ; i--){
    int temp = 0 ;
    if(i+2<n){
        temp = dp[i+2] ;
    }
      int include = nums[i] + temp ;
      int exclude = 0 + dp[i+1] ;
      dp[i] = max(include,exclude) ;
 }
 //step4: return ans
   return dp[0] ;
} 



//Method-3 SpaceOptimisation
int solveUsingSpaceOptimisation(vector<int>& nums){
    int n = nums.size() ;

    int next1 = 0 ;
    int next2 = 0 ;
    int curr ;
 
 for(int i=n-1 ; i>=0 ; i--){
    int temp = 0 ;
    if(i+2<n){
        temp = next2 ;
    }
      int include = nums[i] + temp ;
      int exclude = 0 + next1 ;
      curr = max(include,exclude) ;

      next2 = next1 ;
      next1 = curr ;
 }
  return curr ;
}




    int rob(vector<int>& nums) {
        int index = 0 ;

    //    int ans = solveUsingRecursion(nums,index) ; 
      
    //Method1 - Top Down
    // int n = nums.size() ;
    // vector<int> dp(n+1,-1) ; 
    // int ans = solveUsingMem(nums,index,dp) ; 


    //Method-2 Tabulation/Bottom-Up Approach
    // int ans = solveUsingTabulation(nums) ;

    //Method-3 SpaceOptimisation
    int ans = solveUsingSpaceOptimisation(nums) ;
      
       return ans ;
    }
};