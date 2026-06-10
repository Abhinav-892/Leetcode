class Solution {
public:

   void inorder_Trav(TreeNode* root,vector<int>& inorder){
        if(root==NULL){
            return ;
        }
       inorder_Trav(root->left,inorder) ;
       inorder.push_back(root->val) ;
       inorder_Trav(root->right,inorder) ;  
    }

  void update(TreeNode* root,vector<int>& inorder,int& index){
    if(root==NULL){
        return  ;
    }
   update(root->left,inorder,index) ;

   root->val = inorder[index] ;
   index++ ;

   update(root->right,inorder,index) ;
  }

    TreeNode* convertBST(TreeNode* root) {
          if(root==NULL){
    return NULL ;
  }
  if(root->left==NULL && root->right==NULL){
    return root ;
  }

   vector<int> inorder ; 
   inorder_Trav(root,inorder) ;

   int n = inorder.size() ;

   for(int i=n-1 ; i>=0 ; i--){
    int nextVal = 0 ;
    int currVal = inorder[i] ;

    if(i+1<n){
      nextVal = inorder[i+1] ;
    }
    int sum = currVal + nextVal ;
    inorder[i] = sum ;
   }

  int index = 0 ;
  update(root,inorder,index) ;

 return root ;

    }
};