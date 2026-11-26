class Solution {
public:
    TreeNode* first = NULL ;
    TreeNode* second = NULL ;
    TreeNode* prev = NULL ;

    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }

        inorder(root->left) ;

       if(prev!=NULL && root->val < prev->val){
        if(first==NULL){
            first = prev ;
        }
        second = root ;
       }

      prev = root ;
     inorder(root->right) ;         
    }

    void recoverTree(TreeNode* root) {
        inorder(root) ;
   
    if(first && second){
    swap(first->val,second->val) ;
    }
    }
};