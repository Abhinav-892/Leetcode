class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head ;
        int count = 0 ; 

     while(temp!=NULL && count<k){
        temp = temp->next ;
        count++ ;
     }

    if(count==k){
        ListNode* curr = head ;
        ListNode* forw = NULL ;
        ListNode* prev = NULL ;
        int i=0 ;

       while(curr!=NULL && i<k){
          forw = curr->next ;
          curr->next = prev ;
          prev = curr ;
          curr = forw ;
          i++ ;
       }
       ListNode* recursiveHead = reverseKGroup(curr,k) ;
       head->next = recursiveHead ;  
       return prev ;
    } 

    else{
        return head ;
    }
     
    }
};