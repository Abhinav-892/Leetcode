class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size() ;
    sort(nums.begin(),nums.end()) ;
             
    vector<int> ans ;
    int count = 0;

   for(int i=0 ; i<n ; i++){
      int el = nums[i] ;
      count++ ;

      if((i+1)<n && el==nums[i+1]){
        continue ;
      }

      else if (count > n/3 && (ans.empty() || ans.back() != el)){
        ans.push_back(el) ;
        count = 0 ;
     }
     else{
        count = 0 ;
     }
   }
       return ans ;
    }
};