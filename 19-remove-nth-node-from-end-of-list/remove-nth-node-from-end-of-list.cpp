class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

      ListNode* start = new ListNode(NULL) ;
      start->next = head ; 

      ListNode* main = start->next ;
      int N = 0 ;      
      while(main){
        N++ ;
        main = main->next ;
      } 

      int k = N-n ;
      ListNode* curr = start->next ;
      ListNode* tail = start ; 

     while(k>0){
      tail = curr ;  
      curr = curr->next ;
      --k ;
     } 
 
    ListNode* forw = curr->next ;
    curr->next = NULL ;
    ListNode* temp = curr ;
    curr = forw ;
    delete temp ;
    tail->next = forw ; 

    return start->next ;

    }
};