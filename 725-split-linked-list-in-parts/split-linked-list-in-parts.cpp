class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
     ListNode* temp = head ;
     int N=0 ;
    
     while(temp){
       temp = temp->next ;
       N++ ;
     }

    int ideal = N/k ;
    int extra = N%k ;

    ListNode* it = head ;
    vector<ListNode*> ans(k,NULL) ;  

   for(int i=0 ; i<k && it ; i++){
      ans[i] = it ;

     int actual = ideal + (extra-->0 ? 1:0) ;
    for(int i=0 ; i<actual-1 ; i++){
        it = it->next ;
    }   

    ListNode* nextpart = it->next ;
    it->next = NULL ;
     it = nextpart ;
   } 
 
     return ans ;
    }
};