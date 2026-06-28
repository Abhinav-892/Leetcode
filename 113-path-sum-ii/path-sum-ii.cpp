class Solution {
public:
 
void solve(TreeNode* root, int targetSum,int sum, vector<vector<int>> &ans,vector<int> &nums){
    if(root==NULL){
        return  ;
    }
   sum += root->val ;
   nums.push_back(root->val) ;

 if(root->left == NULL && root->right == NULL){
    if(targetSum == sum){
        ans.push_back(nums) ;
    }
 }  

solve(root->left,targetSum,sum,ans,nums) ;
solve(root->right,targetSum,sum,ans,nums) ;

nums.pop_back() ;

}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans ;
       int sum = 0 ;
       vector<int> nums ;
      solve(root,targetSum,sum,ans,nums) ; 
       return ans ;  
    }
};