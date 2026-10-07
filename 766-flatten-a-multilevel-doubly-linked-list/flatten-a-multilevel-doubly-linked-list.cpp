class Solution {
public:

   Node* solve(Node* head){
    if(head==NULL){
        return NULL ;
    }
 
   Node* it = head ;
   auto tail = it ;
   Node* temp = NULL ;

   while(it!=NULL){
    temp = it->next ;
    if(it->child){
        Node* childtail = solve(it->child) ;
        it->next = it->child ;
        it->next->prev = it ;
        childtail->next = temp ;

        if(temp){
            temp->prev = childtail ;
        } 
         it->child = NULL ;
    }
    else{
        tail = it ;
        it = it->next ;
    }
   }
     return tail ;
   }


    Node* flatten(Node* head) {
        solve(head) ;
        return head ;
    }
};