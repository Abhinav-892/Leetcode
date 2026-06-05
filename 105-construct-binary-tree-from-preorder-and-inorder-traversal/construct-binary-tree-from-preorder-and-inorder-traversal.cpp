class Solution {
public:

int findindex(vector<int> inorder,int element){
    int n = inorder.size() ;

for(int i=0 ; i<n ; i++){
    if(inorder[i]==element){
        return i ;
    }
}
return -1 ;
}

TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preorderindex,int inorderstart,int inorderend){

if(preorderindex>preorder.size()-1){
    return NULL ;
}

if(inorderstart>inorderend){
    return NULL ;
}

int element = preorder[preorderindex] ;
 preorderindex++ ;

int elementindex = findindex(inorder,element) ;

TreeNode* root = new TreeNode(element) ; 

 root->left = solve(preorder,inorder,preorderindex,inorderstart,elementindex-1) ;
 root->right = solve(preorder,inorder,preorderindex,elementindex+1,inorderend) ;
  return root ;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0 ;
        int inorderstart = 0 ;
        int inorderend = inorder.size()-1 ;
        TreeNode* root = solve(preorder,inorder,preorderindex,inorderstart,inorderend) ;
           return root ;
    }
};