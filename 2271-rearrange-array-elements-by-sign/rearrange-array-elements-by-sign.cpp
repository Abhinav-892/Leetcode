class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int> pos ; 
     vector<int> neg ;

    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i]<0){
            neg.push_back(nums[i]) ;
        }
        else{
            pos.push_back(nums[i]) ;
        }
    } 

    int i = 0 ;
    int j = 0 ;
    int k = 0 ;

    while(i<nums.size()){
        nums[i] = pos[j] ;
          i++ ;
          j++ ;
        nums[i] = neg[k] ;
          k++ ;
          i++ ;   
    }
       return nums ;
    } 
};