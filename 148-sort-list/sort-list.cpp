class Solution {
public:

   ListNode* findmid(ListNode* head){
    ListNode* slow = head ;
    ListNode* fast = head->next ;

    while(fast && fast->next){
        slow = slow->next ;
        fast = fast->next->next ;
    }
        return slow ;
   }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* ans = new ListNode(-1) ;
        ListNode* mptr = ans ;

     while(left && right){
        if(left->val < right->val){
            mptr->next = left ;
            left = left->next ;
        }
        else{
            mptr->next = right ;
            right = right->next ;
        }
        mptr = mptr->next ;
     }

    if(left){
        mptr->next = left ;
    }  

    if(right){
        mptr->next = right ;
    }
      return ans->next ;
    }   

    ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head ;
    }        

    ListNode* mid = findmid(head) ;

    ListNode* left = head ;
    ListNode* right = mid->next ;

    mid->next = NULL ;

    left = sortList(left) ;
    right = sortList(right) ;

    return merge(left,right) ;

    }
};