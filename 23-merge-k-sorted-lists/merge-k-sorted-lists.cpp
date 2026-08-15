class compare{
    public : 
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val ;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode* , vector<ListNode*> ,compare> pq ;
      ListNode* head = NULL ;
      ListNode* tail = NULL ;

     int rowsize = lists.size() ;  
  
     for(int row=0 ; row<rowsize ; row++){
        ListNode* temp = lists[row] ;
        if(temp!=NULL){
           pq.push(temp) ;
        }
     }

     while(!pq.empty()){
        ListNode* temp = pq.top() ;
        pq.pop() ;

       if(head==NULL && tail==NULL){
          head = temp ;
          tail = temp ;
       }
       else{
        tail->next = temp ;
        tail = temp ;
       }
        
        if(tail->next!=NULL){
            pq.push(tail->next) ;
        }
     }
       return head ;
    }
};