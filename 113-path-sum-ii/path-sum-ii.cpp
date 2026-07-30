class Solution {
public:
 
void solve(vector<vector<int>> &ans,vector<int> &nums,TreeNode* root, int targetSum,int sum){
        if(root==NULL){
            return ;
        }
        sum += root->val ;
        nums.push_back(root->val) ;

    if(root->left==NULL && root->right==NULL){
        if(targetSum==sum){
            ans.push_back(nums) ;
        }
    }

     solve(ans,nums,root->left,targetSum,sum) ;
     solve(ans,nums,root->right,targetSum,sum) ;
          nums.pop_back() ;
    }  



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      int sum = 0 ;
      vector<vector<int>> ans ;
      vector<int> nums ;
      solve(ans,nums,root,targetSum,sum) ;         
     return ans ;
    }
};