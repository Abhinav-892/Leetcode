class Solution {
public:

    bool solve(TreeNode* root,long long lb,long long rb){
    if(root==NULL){
        return true ;
    }
    bool isRootOK = root->val > lb && root->val < rb ;
    bool ansFromLeft = solve(root->left,lb,root->val) ;
    bool ansFromRight = solve(root->right,root->val,rb) ;
   
    return isRootOK && ansFromLeft && ansFromRight ;
   
   }

    bool isValidBST(TreeNode* root) {
    long long lb = LONG_MIN ;
    long long rb = LONG_MAX ;
    return  solve(root,lb,rb) ; 
    }
};