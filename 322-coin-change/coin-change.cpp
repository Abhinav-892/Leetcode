class Solution {
public:

   int solveUisngRec(vector<int>& coins, int amount){
    if(amount == 0){
        return 0 ;
    }
    int mini = INT_MAX ;

    for(int i=0 ; i<coins.size() ; i++){
        if(coins[i]<=amount){

            //maine ek coin use karliya
            int recursionKaAns = solveUisngRec(coins,amount-coins[i]) ;
        
         if(recursionKaAns != INT_MAX){
            // ek valid ans mila h
            // it may or may not be minimum

            //Yaha 1+recursionKaAns,here "1" represent
            //the single coin we used in line 14
            mini = min(mini,1 + recursionKaAns) ;
         }
        }
      }
      return mini ;
   }

//Method 1 
// 1d DP

int solveUsingMem(vector<int>& coins, int amount,vector<int>& dp){
    if(amount == 0){
        return 0 ;
    }

   if(dp[amount] != -1){
    return dp[amount] ;
   }

 int mini = INT_MAX ;

    for(int i=0 ; i<coins.size() ; i++){
        if(coins[i]<=amount){
            //maine ek coin use karliya
            int recursionKaAns = solveUsingMem(coins,amount-coins[i],dp) ;
        
         if(recursionKaAns != INT_MAX){
            mini = min(mini,1 + recursionKaAns) ;
         }
        }
      }
      dp[amount] = mini ;
      return mini ;
}


    int coinChange(vector<int>& coins, int amount) {
      int n = amount ;
      vector<int> dp(n+1,-1) ;
      int ans = solveUsingMem(coins,amount,dp) ;
        if(ans == INT_MAX){
            return -1 ;
        }
        else{
            return ans ;
        }

    }
};