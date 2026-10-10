class BrowserHistory {
public:
    struct Node { 
        string value;
        struct Node *next;
        struct Node *prev;
    };
    struct Node *curr;
    BrowserHistory(string homepage) {
        struct Node * newNode=new Node();
        newNode->value=homepage;
        newNode->next=NULL;
        newNode->prev=NULL;
        curr=newNode; 
    }
    
    void visit(string url) {
        curr->next=new Node();
        curr->next->value=url;
        curr->next->next=NULL;
        curr->next->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps--){
            curr=curr->prev;
        }
        return curr->value;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps--){
            curr=curr->next;
        }
        return curr->value;
    }
};