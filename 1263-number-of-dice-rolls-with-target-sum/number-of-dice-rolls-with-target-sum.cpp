class Solution {
public:

  long long int mod = 1000000007 ; 

   int solveUsingRec(int n,int k,int target){
    if(n<0 || target<0){
        return 0 ;
    }
    if(n==0 && target==0){
        return 1 ;
    }
    if(n==0 && target!=0){
        return 0 ;
    }
    if(n!=0 && target==0){
        return 0 ;
    }

    int ans = 0 ;
    for(int val=1; val<=k; val++){
        ans = ans + solveUsingRec(n-1,k,target-val) ;
    }
    return ans ;
   }

  
// 2D DP
//Method1 

int solveUsingMem(int n,int k,int target,vector<vector<long long int>>& dp){
    if(n<0 || target<0){
        return 0 ;
    }
    if(n==0 && target==0){
        return 1 ;
    }
    if(n==0 && target!=0){
        return 0 ;
    }
    if(n!=0 && target==0){
        return 0 ;
    }

    if(dp[n][target] != -1){
        return dp[n][target] ;
    }
    
    int ans = 0 ;
    for(int val=1; val<=k; val++){
        ans = (ans%mod + solveUsingMem(n-1,k,target-val,dp)%mod)%mod ;
    }
    dp[n][target] = ans ;
    return ans ;
}


//Method2 tabulation

 int solveUsingTabulation(int n,int k,int target){
    vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,0));
    dp[0][0] = 1 ;

  for(int a=1 ; a<=n; a++){
    for(int t=1 ; t<=target; t++){
        long long int ans = 0 ;
        for(int val=1; val<=k; val++){
            long long int temp = 0 ;
            if(t-val>=0){
                temp = dp[a-1][t-val]%mod ;
            }
        ans = (ans%mod + temp)%mod ;
    }
      dp[a][t] = ans ;
    }
  }
     return dp[n][target] ;
 }


//Method3 Space_Optimisation

int solveUsingOS(int n,int k,int target){
    vector<int> prev(target+1,0) ;
    vector<int> curr(target+1,0) ;

    prev[0] = 1 ;

    for(int a=1 ; a<=n; a++){
    for(int t=1 ; t<=target; t++){
        long long int ans = 0 ;
        for(int val=1; val<=k; val++){
            long long int temp = 0 ;
            if(t-val>=0){
                temp = prev[t-val]%mod ;
            }
        ans = (ans%mod + temp)%mod ;
    }
      curr[t] = ans ;
    }
    //bhuljata hu
    //Shifting
   prev = curr ;
}
 return prev[target] ;
}


    int numRollsToTarget(int n, int k, int target) {
    //    int ans = solveUsingRec(n,k,target) ;
    //    return ans ;       

    //Method1 
    // vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,-1));
    // int ans = solveUsingMem(n,k,target,dp) ;
    //   return ans ;
    
    //Method2
    // int ans = solveUsingTabulation(n,k,target) ;  
    // return ans ;

    //Method3
    int ans = solveUsingOS(n,k,target) ;
    return ans ;
    }
};