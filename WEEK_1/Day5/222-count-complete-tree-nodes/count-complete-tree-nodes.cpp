class Solution {
public:

int leftheight(TreeNode* root){
int h = 0 ;

while(root){
    h++ ;
  root = root->left ;
}
return h ;
}

int rightheight(TreeNode* root){
int h = 0 ;

while(root){
    h++ ;
   root = root->right ;
}
return h ;
}

    int countNodes(TreeNode* root) {
 
  if(root==NULL){
    return 0 ;
  }

  int lh = leftheight(root) ;
  int rh = rightheight(root) ;

  if(lh==rh){
    return pow(2,lh)-1 ;
  }

  int leftcount = countNodes(root->left) ;
  int rightcount = countNodes(root->right) ; 
    return leftcount + rightcount + 1 ;
    }
};