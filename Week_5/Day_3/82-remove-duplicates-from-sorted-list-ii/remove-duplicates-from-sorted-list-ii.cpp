class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = new ListNode(0);  
    temp->next = head;                  
    ListNode* prev = temp;
    ListNode* curr = head;

    while (curr != NULL) {
        if (curr->next != NULL && curr->val == curr->next->val) {
            int val = curr->val;
            while (curr != NULL && curr->val == val) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            prev->next = curr; 
        } 
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return temp->next;
    }
};