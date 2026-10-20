class Solution {
public:

    bool solve(TreeNode* root, int targetSum,int sum){      
    if(root==NULL){
      return false ;
    }

    sum += root->val ;

    if(root->left==NULL && root->right==NULL){
      if(sum==targetSum){
        return true ;
      }
      else{
        return false ;
      }
    }

    bool left = solve(root->left,targetSum,sum) ;
    bool right = solve(root->right,targetSum,sum) ;

    bool ans = left || right ;
    return ans ;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0 ;
    bool ans = solve(root,targetSum ,sum) ;
    return ans ;
    }
};