class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

     if(!head){
        return 0 ;
     }

     ListNode* slow = head ;
     ListNode* fast = head->next ;
     ListNode* LastNode = 0 ;
     int sum ;
  
     while(fast){ 
     
    if(fast->val!=0){
       sum += fast->val; 
    }
    else{
        slow->val = sum ;
        LastNode = slow ;
        slow = slow->next ;
        sum = 0 ;
    }
        fast = fast->next ;
    } 
      ListNode* temp = slow ;
      
      LastNode->next = 0 ;

    while(temp){
        ListNode* next = temp->next ;
        delete temp ;
        temp = next ;
    }
            return head ;
    }
};