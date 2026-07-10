
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
   ListNode* slow = head ;
   ListNode* fast = head ;

  if(head->next==NULL){
    return NULL ;
  }

  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next ;
    fast = fast->next->next ;
  }

    ListNode* temp = head ;
    int count = 0 ;

    while(temp!=slow){
        temp=temp->next ;
        count++ ;
    }
  
    ListNode* prev = head ;
     
    for(int i=0 ; i<count-1 ; i++){
        prev = prev->next ;
    }

    prev->next = slow->next ;
    slow->next = NULL ;
    delete slow ;

   return head ;
 
    }
};