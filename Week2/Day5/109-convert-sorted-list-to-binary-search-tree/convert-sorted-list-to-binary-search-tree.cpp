class Solution {
public:

    int getLen(ListNode* head){
        ListNode* temp = head ;
        int count = 0 ;
     
     while(temp!=NULL){ 
        count ++ ;
     temp = temp->next ;
     }
        return count ;  
    }

    TreeNode* solve(ListNode* &head,int n){
        if(head == NULL){
            return NULL ;
        }
        if(n<=0){
            return NULL ;
        }

       TreeNode* leftSubtree = solve(head,n/2) ;

       int element = head->val ;
       TreeNode* root = new TreeNode(element) ;
       root->left = leftSubtree ;

       head = head->next ;
  
       TreeNode* rightSubtree = solve(head,n-n/2-1) ;
       root->right = rightSubtree ;    
             return root ;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLen(head) ;
        TreeNode* root = solve(head,len) ;
        return root ;
    }
};