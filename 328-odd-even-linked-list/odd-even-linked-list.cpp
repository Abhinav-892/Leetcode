class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

    if(head==NULL){
        return NULL ;
    }    

    ListNode* h1 = head ;
    ListNode* h2 = head->next ;
    ListNode* evenhead = h2 ; 
       
     while(h2 && h2->next){
      h1->next = h2->next ;
      h2->next = h2->next->next ;
      h1 = h1->next ;
      h2 = h2->next ;
    }

   h1->next = evenhead ;

      return head ; 
    }
};