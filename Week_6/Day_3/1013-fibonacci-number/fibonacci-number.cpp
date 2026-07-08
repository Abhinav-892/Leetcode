class Solution {
public:

 int solveUsingBasicRec(int n){
    if( n==0 || n==1 ){
        return n ;
    }
   int ans = solveUsingBasicRec(n-1) + solveUsingBasicRec(n-2) ;
    return ans ;
 }

//1. Top-down approach
// 1d dp
 int solveUsingMem(int n, vector<int>& dp){
    if( n==0 || n==1 ){
        return n ;
    }

  if(dp[n]!=-1){
    return dp[n] ;
  }

   int ans = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp) ;
    dp[n] = ans ;
 
    return dp[n] ;
 }

 //2. Bottom-Up(or Tabulation method)
 // little better optimisation than method 1


int solveusingTabulation(int n){
    //step1 : create dp array
  vector<int> dp(n+1,-1) ;

//step2 : analyse base cases and fill dp array
if(n==0){
    return 0 ;
}

if(n==1){
    return 1 ;
}

dp[0] = 0 ;
dp[1] = 1 ;

for(int i=2; i<=n ; i++){
    int ans = dp[i-1] + dp[i-2] ;
    dp[i] = ans ;
}
  return dp[n] ;
} 

//3. Space optimisation Method
// Little better optimisation than method 2

int solveUsingTabulationSO(int n){

if(n==0){
    return 0 ;
}
if(n==1){
    return 1 ;
}

int prev2 = 0 ;
int prev1 = 1 ;
int curr = -1 ;

for(int i=2 ; i<=n ; i++){
    curr = prev1 + prev2 ;
    prev2 = prev1 ;
    prev1 = curr ;
}
  return curr ;
}

    int fib(int n) {

        //1.Method
        // vector<int> dp(n+1,-1) ;  
        // int ans = solveUsingMem(n,dp) ;

        // 2.Method 
        // int ans = solveusingTabulation(n) ;

        // 3.Method
        int ans = solveUsingTabulationSO(n) ; 
        return ans ;      
    }
};