class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp = head ;
      int count = 0 ;
       ListNode* prev = NULL ;
    while(temp){
       if(count==k){
        break ;
       }  
       count++ ;
       temp = temp->next ;
    }  
       
     if(count==k){
        ListNode* curr = head ;
       
        ListNode* forw = NULL ;
        int i=0 ;

     while(curr && i<k){
        forw = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forw ;
        i++ ;
     }    
       
    ListNode* recursion = reverseKGroup(curr,k) ;
    head->next = recursion ;
     }  
     else{
        return head ;
     }
       return prev ;
    }
};