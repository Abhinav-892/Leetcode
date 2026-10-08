class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

     if(!head){
        return 0 ;
     }

     ListNode* slow = head ;
     ListNode* fast = head->next ;
     ListNode* LastNode = 0 ;
     int sum = 0 ;
  
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
      
      LastNode->next = NULL ;
            return head ;
    }
};