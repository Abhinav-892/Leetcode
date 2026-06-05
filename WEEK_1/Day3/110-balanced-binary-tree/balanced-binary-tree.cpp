/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  int getHeight(TreeNode* root){
     if(root == NULL){
        return 0;
     }
     int leftdepth = getHeight(root->left) ;
     int rightdepth = getHeight(root->right) ;
     int ans = max(leftdepth,rightdepth) + 1 ;
     return ans ;   
  }

    bool isBalanced(TreeNode* root) {

    if(root == NULL){
        return true ;
    }

        int leftnode = getHeight(root->left) ;
        int rightnode = getHeight(root->right) ;

       int absdiff = abs(leftnode - rightnode) ;

       if(absdiff>1){
           return false ;       
       }

       else{
        
       bool leftans = isBalanced(root->left) ;
       bool rightans = isBalanced(root->right) ;

       if(leftans==true && rightans==true){
        return true ;
       }
       else{
       return  false ;
       }

       }

    }
};