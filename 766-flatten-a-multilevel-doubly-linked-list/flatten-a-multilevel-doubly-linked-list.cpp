class Solution {
public:

  Node* solve(Node* head){

  if(head==NULL){
    return NULL ;
  }

  Node* it = head ;
  auto tail = it ;

  while(it){
    if(it->child){
       Node* childtail = solve(it->child) ;
       Node* temp = it->next ;
       it->next = it->child ;
       it->next->prev = it ;
       childtail->next = temp ;
     if(temp){
        temp->prev = childtail ;
     }
       it->child = NULL ;
    }
    tail = it ;
    it = it->next ;
  }
       return tail ;
  } 

    Node* flatten(Node* head) {
       solve(head) ;
       return head ;        
    }
};