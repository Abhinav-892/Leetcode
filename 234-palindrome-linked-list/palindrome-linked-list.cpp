class Solution {
public:

   int getlen(ListNode* head){
      ListNode* temp = head ;
      int len = 0 ;
      while(temp!=NULL){
          len++ ;
          temp = temp->next ;
      }
      return len ;
   }

   ListNode* findmiddle(ListNode* head){

    if(head->next==NULL){
        return NULL ;
    }

       ListNode* slow = head ;
       ListNode* fast = head ;
    while(fast!=NULL && fast->next!=NULL){
         slow = slow->next ;
         fast = fast->next->next ;
    }
      return slow ;
   }

  ListNode* reverse(ListNode* head){
    ListNode* curr = head ;
    ListNode* prev = NULL ;
  while(curr!=NULL){
    ListNode* forw = curr->next ;
    curr->next = prev ;
    prev = curr  ;
    curr = forw ;
  }
   return prev ;
  }
   

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return NULL ;
        }

    int len = getlen(head) ;

    if(len==1){
        return true ;
    }

    ListNode* middle = findmiddle(head) ;
    ListNode* finalmiddle = NULL ;
   
    if(len&1){
       finalmiddle = middle->next ;   
    }
    else{
        finalmiddle = middle ;
    }

    ListNode* revHead = reverse(finalmiddle) ;
    ListNode* temp = head ;

    while(temp!=NULL && revHead!=NULL){
        if(temp->val==revHead->val){
            temp = temp->next ;
            revHead = revHead->next ;
        }
        else{
            return false ;
        }
    }
        return true ;
    }
};