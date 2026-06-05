 class Solution {
    public:
int findindex(vector<int> inorder, int element) {
    int n = inorder.size();

    for (int i = 0; i < n; i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

TreeNode* solve(vector<int>& postorder, vector<int>& inorder,
                int& postorderindex, int inorderstart, int inorderend) {

    if (postorderindex < 0) {
        return NULL;
    }

    if (inorderstart > inorderend) {
        return NULL;
    }

    int element = postorder[postorderindex];
    postorderindex--;

    int elementindex = findindex(inorder, element);

    TreeNode* root = new TreeNode(element);

    root->right =
        solve(postorder, inorder, postorderindex, elementindex + 1, inorderend);

    root->left = solve(postorder, inorder, postorderindex, inorderstart,
                       elementindex - 1);

    return root;
                }
   
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int postorderindex = postorder.size() - 1;
            int inorderstart = 0;
            int inorderend = inorder.size() - 1;
            TreeNode* root = solve(postorder, inorder, postorderindex,
                                   inorderstart, inorderend);
            return root;
        }
};