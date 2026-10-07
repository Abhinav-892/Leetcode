class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head ; 
        ListNode* fast = head ;

    while(fast && fast->next){
        slow = slow->next ;
        fast = fast->next->next ;
    }

    ListNode* curr = slow ;
    ListNode* prev = NULL ;

    while(curr){
        ListNode* forw = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forw ;
    }

    ListNode* head2 = prev ;
    ListNode* head1 = head ;
    int ans = 0 ;
  
    while(head2){
      int sum = head1->val + head2->val ;
      ans = max(ans,sum) ;
      head1 = head1->next ;
      head2 = head2->next ; 
    }
       return ans ;
    }
};