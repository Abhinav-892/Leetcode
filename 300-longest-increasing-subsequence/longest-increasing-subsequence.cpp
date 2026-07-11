class Solution {
public:

   int  solveUsingRec(vector<int>& arr,int curr,int prev){
    if(curr >= arr.size()){
        return 0 ;
    }

    int includeAns = 0 ;
    
    if(prev==-1 || arr[curr]>arr[prev]){
        includeAns = 1 + solveUsingRec(arr,curr+1,curr) ;
    }
        int excludeAns = 0 + solveUsingRec(arr,curr+1,prev) ;
        int finalAns = max(includeAns,excludeAns) ;
        return finalAns ;
   }
 


 //Method 1 : Top-down approach 
  
  int solveUsingMem(vector<int>& arr,int curr,int prev,vector<vector<int>>&dp){
    if(curr >= arr.size()){
        return 0 ;
    }

   if(dp[curr][prev+1]!=-1){
    return dp[curr][prev+1] ;
   }

    int includeAns = 0 ;
    if(prev==-1 || arr[curr]>arr[prev]){
        includeAns = 1 + solveUsingMem(arr,curr+1,curr,dp) ;
    }
        int excludeAns = 0 + solveUsingMem(arr,curr+1,prev,dp) ;
        int finalAns = max(includeAns,excludeAns) ;
        dp[curr][prev+1] = finalAns ;
        return finalAns ;
  }
  
 //Method 2 : Bottom-Up approach 

int solveUsingTabulation(vector<int>& arr) {
    int n = arr.size() ;
     vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;

  for(int curr=n-1; curr>=0 ; curr--){
    for(int prev = curr-1 ; prev>=-1 ; prev--){
        int includeAns = 0;
        if(prev==-1 || arr[curr]>arr[prev]){
        includeAns = 1 + dp[curr+1][curr+1] ;
    }
        int excludeAns = 0 + dp[curr+1][prev+1] ;
        dp[curr][prev+1] = max(includeAns,excludeAns) ;
    }
  } 
   return dp[0][0] ;
}





    int lengthOfLIS(vector<int>& nums) {
        int prev = -1 ;
        int curr = 0 ;
        // int ans = solveUsingRec(nums,curr,prev) ;
       
       //2d DP
       // Methode 1
    //    int n = nums.size() ;
    //    vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
    //    int ans = solveUsingMem(nums,curr,prev,dp) ;

      // Methode 2
      int ans = solveUsingTabulation(nums) ;
        return ans ;
    }
};