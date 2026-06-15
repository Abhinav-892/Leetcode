class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

  vector<int> ans ;
  deque<int> dq ;

  for(int i=0 ; i<k ; i++){
  while(!dq.empty() && nums[dq.back()]<nums[i]){
        dq.pop_back() ;
  }
 dq.push_back(i) ; 
  }
   int element = nums[dq.front()] ;
   ans.push_back(element) ;

for(int i=k ; i<nums.size() ; i++){

if(!dq.empty() && i-dq.front()>=k){
    dq.pop_front() ;
}

while(!dq.empty() && nums[dq.back()]<nums[i]){
    dq.pop_back() ;
}

dq.push_back(i) ;
int element = nums[dq.front()] ;
ans.push_back(element) ;
}
    return ans ;
    }
};