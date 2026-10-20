class Solution {
public:

 int find(vector<int>& inorder,int element){

 for(int i=0 ; i<inorder.size() ; i++){
    int nums = inorder[i] ;
    if(nums==element){
        return i ;
    }
 }
    return -1 ;
 }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preindex,int inorderstart,int inorderend){

     if(preindex >= preorder.size()){
        return NULL ;
     }

     if(inorderstart>inorderend){
        return NULL ;
     }

     int element = preorder[preindex] ;
     preindex++ ;

    TreeNode* root = new TreeNode(element) ;

    int index = find(inorder,element) ;
      
    root->left = solve(preorder,inorder,preindex,inorderstart,index-1) ;
    root->right = solve(preorder,inorder,preindex,index+1,inorderend) ;
    
    return root ;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preindex = 0 ;
       int inorderstart = 0 ;
       int inorderend = inorder.size() ;

      TreeNode* root = solve(preorder,inorder,preindex,inorderstart,inorderend) ; 
      return root ;
    }
};