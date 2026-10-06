class Solution {
public:

    ListNode* add(ListNode* l1, ListNode* l2){    
     ListNode* ans = new ListNode(-1) ;
     auto it = ans ;
     int carry = 0 ;
 
    while(l1!=NULL || l2!=NULL || carry!=0){
        int a = l1!=NULL ? l1->val : 0 ;
        int b = l2!=NULL ? l2->val : 0 ;
    
      int sum = a + b + carry ;
      int digit = sum%10 ;
       carry = sum/10 ;

    it->next = new ListNode(digit) ;
    it = it->next ; 

     l1 = l1!=NULL ? l1->next : 0 ;
     l2 = l2!=NULL ? l2->next : 0 ;

    }
      return ans->next ;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return add(l1,l2) ;         
    }
};