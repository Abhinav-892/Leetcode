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

    int getlen(ListNode* head){
        int len = 0 ;
        ListNode* temp = head ;

     while(head){
        len++ ;
        head = head->next ;
     }
       return len ;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL ;
        }

    int len = getlen(head) ;

    if(len==1){
        return head ;
    }

    k = k%len ; 

   
   if(k==0){
    return head ;
   }

    int lastnode = len-k-1 ;
    ListNode* lastNode = head ;

    for(int i=0 ; i<lastnode ; i++){
        lastNode = lastNode->next ;
    }  
 
     ListNode* Newhead = lastNode->next ;

     lastNode->next = NULL ; 

     ListNode* it = Newhead ;

     while(it->next){
        it = it->next ;
     } 

    it->next = head ;

    return Newhead ;

    }
};