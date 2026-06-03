class Solution {
public:

 int maxDepth(TreeNode* root){
    if(root==NULL){
        return 0 ;
    }

    int leftDepth = maxDepth(root->left) + 1 ;
    int rightDepth = maxDepth(root->right) + 1 ;
    int ans = max(leftDepth,rightDepth) ;
    return ans ;
 }


    int diameterOfBinaryTree(TreeNode* root) {
     if(root==NULL){
        return 0 ;
     }

     int option1 =  maxDepth(root->left) +  maxDepth(root->right) ;
     int option2 =  diameterOfBinaryTree(root->left) ;
     int option3 = diameterOfBinaryTree(root->right) ;

    int ans = max(option1,max(option2,option3)) ;
     return ans ;
    }
};