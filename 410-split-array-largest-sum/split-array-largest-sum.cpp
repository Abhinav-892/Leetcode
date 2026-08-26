class Solution {
public:

    bool check_valid(int n, vector<int>&arr, int m , int mid){
 
 int pagesum = 0 ;
 int count = 1 ;

 for(int i=0 ; i<n ; i++){

if(arr[i]>mid){
  return false ;
}

if(pagesum + arr[i]>mid){
  count ++ ;
  pagesum = arr[i] ;
  if(count>m){
    return false ;
  }
}
else{
  pagesum = pagesum + arr[i] ;
}
 } 
  return true ;
  }


    int splitArray(vector<int>& nums, int k) {
    int start = 0 ;
    int end = 0 ;
    int ans = -1 ;
    int n = nums.size() ;

    if(k>n){
      return -1 ;
    }

    for(int i=0 ; i<n ; i++){
      end = end + nums[i] ;
    }

    while(start<=end){
  
  int mid = (start+end)/2 ;

  if(check_valid(n,nums,k,mid)){
    ans = mid ;
    end = mid-1 ;
  }
  
  else {
    start = mid+1 ;
  }

    }
   return ans ;
    }
};