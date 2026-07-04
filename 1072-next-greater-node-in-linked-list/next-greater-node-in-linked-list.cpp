class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ll ;
 
     while(head){
        ll.push_back(head->val) ;
        head = head->next ;
     }

     vector<int> ans(ll.size()) ;
     stack<int> st ;   
  
     for(int i=0 ; i<ll.size() ; i++){
    
     while(!st.empty() && ll[i]>ll[st.top()]){
         int index = st.top() ;
        st.pop() ;
        ans[index] = ll[i] ;
     }  
       st.push(i) ;  
    } 
      return ans ;
    }
};