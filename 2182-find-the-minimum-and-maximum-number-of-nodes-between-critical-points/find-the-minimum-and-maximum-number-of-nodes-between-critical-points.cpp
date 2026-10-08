class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> ans = {-1,-1} ;
       ListNode* prev = head ;
  
    if(!prev){
        return ans ;
    } 

    ListNode* curr = head->next ;
    if(!curr){
        return ans ;
    }

    ListNode* nxt = head->next->next ;
    if(!nxt){
        return ans ;
    }

    int firstcp = -1 ;
    int lastcp = -1 ;
    int i = 1 ;
    int mindis = INT_MAX ;

    while(nxt){

    bool isCP = ((curr->val>prev->val && curr->val>nxt->val) || (curr->val<prev->val && curr->val<nxt->val)) ;

    if(isCP){
        if(firstcp==-1){
            firstcp = i ;
            lastcp = i ;
        }
        else{
            mindis = min(mindis,i-lastcp) ;
            lastcp = i ;
        }
    } 
     i++ ;

    prev = prev->next ;
    curr = curr->next ;
    nxt  = nxt->next ;  
    }

     if(firstcp==lastcp){
        return ans ;
     }
     else{
        ans[0] = mindis ;
        ans[1] = lastcp-firstcp ;
     }
        return ans ;  
    }
};