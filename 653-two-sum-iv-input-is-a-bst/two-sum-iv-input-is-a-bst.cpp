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

   bool check(vector<int>& inorder,int k){
    int n = inorder.size() ;  
    int s=0 ;
    int e=n-1 ;

    while(s<e){
    int sum = 0 ; 
    
    sum = inorder[s] + inorder[e] ; 
    
        if(sum==k){
            return true ;
        }
        else if(sum>k){
             e-- ;
        }
        else{
            s++ ;
        }
    } 
       return false ;
   }

    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false ;
        }
        vector<int> inorder ;
        inorder_Trav(root,inorder) ;
        bool ans = check(inorder,k) ;
        return ans ;
    }
};