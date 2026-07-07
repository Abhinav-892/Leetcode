/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int k=2 ;
        ListNode* temp = head ;
        int count = 0 ;

     while(temp!=NULL && count<k){
        temp = temp->next ;
        count ++ ;
     }

    
  if(count==k){

    ListNode* prev = NULL ;
    ListNode* forw = NULL ;
    ListNode* curr = head ;

    int i = 0 ;

  while(i<k){
   forw = curr->next ;
   curr->next = prev ;
   prev = curr ;
   curr = forw ;
    i++ ;
  }
   ListNode* recursiveHead = swapPairs(forw) ;

   head->next = recursiveHead ;
       return prev ;
     }
  
   else {
        return head ;
    } 
    }
};