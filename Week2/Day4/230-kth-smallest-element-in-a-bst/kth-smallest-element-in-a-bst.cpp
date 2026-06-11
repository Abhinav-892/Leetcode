class Solution {
public:

  void solve(TreeNode* root,int k,TreeNode* &ans,int& count){
    if(root==NULL){
        return ;
    }
    
   solve(root->left,k,ans,count) ;
   count++ ;
    if(count==k){
    ans = root ;
    return ;
   } 
  solve(root->right,k,ans,count) ;
 
  }

  int kthSmallest(TreeNode* root, int k) {
  int count = 0 ;


  TreeNode* ans = NULL ;
  solve(root,k,ans,count) ;
  return ans->val ;
    }
};