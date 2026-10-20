class Solution {
public:
  
  int maxdepth(TreeNode* root){
    if(root==NULL){
        return 0 ;
    }
    int left = maxdepth(root->left)  ;
    int right = maxdepth(root->right)  ;
    int ans = max(left,right) + 1;
    return ans ;
  }
  
  
  int diameterOfBinaryTree(TreeNode* root) {
   if(root==NULL){
    return 0 ;
   }

  int option1 = maxdepth(root->left) + maxdepth(root->right) ;
  int option2 = diameterOfBinaryTree(root->left) ;
  int option3 = diameterOfBinaryTree(root->right) ;

  int ans = max(max(option1,option2),option3) ;
  return ans ;     
 }
};