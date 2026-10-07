class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

     int N = 0;
     ListNode* temp = head ;

     while(temp){
        temp = temp->next ;
        N++ ;
     }

        ListNode* first = head;

        for(int i = 1; i < k; i++) {
            first = first->next;
        }
    
        ListNode* node1 = first;
        ListNode* second = head;

      for(int i=0 ; i<N-k ; i++){
        second = second->next ;
      }    
  
      
    
        swap(node1->val, second->val);

        return head;
    }
};