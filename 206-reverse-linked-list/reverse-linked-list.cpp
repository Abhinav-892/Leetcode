
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     if(head==NULL){
        return NULL ;
     }

    ListNode* curr = head ;
    ListNode* prev = NULL ;


    while(curr!=NULL){
      ListNode* forw = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forw ;
    } 
         head = prev ;

       return prev ;  

    }
};