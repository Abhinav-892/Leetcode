class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

   ListNode*fp = new ListNode(-1) ;
   ListNode*sp = new ListNode(-1) ;

   ListNode* fptail = fp ;   // auto is a keyword that let the compiler automatically detect the data type.
   auto sptail = sp ;   // you can also write ListNode* sptail

   auto it = head ;

   while(it){
   
  if(it->val<x){
    fptail->next = it ;
    fptail = fptail->next ;
  }
  else{
    sptail->next = it ;
    sptail = sptail->next ;
    } 
    it = it->next ;
   }

  fptail->next = sp->next ;
  sptail->next = NULL ;

     return fp->next ;
    }
};