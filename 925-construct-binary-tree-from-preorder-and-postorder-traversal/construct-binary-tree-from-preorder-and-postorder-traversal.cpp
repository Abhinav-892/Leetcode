class Solution {
public:

  TreeNode* build(vector<int>& pre,int pl,int pr ,vector<int>& post,int pol,int por,
  unordered_map<int,int>& postMap){
        if(pl>pr){
             return NULL ;
        }
        auto root = new TreeNode(pre[pl]) ;

        if(pl==pr){
            return root ;
        }

        int leftRootVal = pre[pl+1] ;

        int idx = postMap[leftRootVal] ;
        int leftSize = idx-pol+1 ;

       root->left = build(pre,pl+1,pl+leftSize,post,pol,idx,postMap) ;
       root->right = build(pre, pl+leftSize+1 ,pr ,post ,idx+1 ,por-1,postMap) ;
       return root ;
  }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size() ;
        unordered_map<int,int>postMap ;
        for(int i=0 ; i<n;i++){
            postMap[postorder[i]] = i ;
        }
        return build(preorder,0,n-1,postorder,0,n-1,postMap) ;
    }
};