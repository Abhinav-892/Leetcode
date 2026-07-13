class Solution {
public:

int findpivotindex(vector<int>& nums ){
int n = nums.size() ;
   int s = 0 ;
   int e = n-1 ;
   

   while(s<=e){

  int mid = (s+e)/2 ;

  if(s==e){
    return mid ;
  }

  if((mid+1 < n) && nums[mid]>nums[mid+1]){
     return mid ;
  }

  if(nums[s]>nums[mid]){
     e = mid-1 ;
  }

  else{
    s = mid+1 ;
  }
   }

return -1 ;

}

int binarysearch(vector<int>& nums, int target,int s,int e){
int n = nums.size() ;
 

while(s<=e){
int mid = (s+e)/2 ;
if(nums[mid]==target){
    return mid ;
}
else if(target>nums[mid]){
    s = mid+1 ;
}
else{
    e = mid-1 ;
}
}
return -1 ;
}

    int search(vector<int>& nums, int target) {

      
    
     int pivotindex =  findpivotindex(nums) ;

       int n = nums.size() ;

     if(target>=nums[0] && target<=nums[pivotindex]){
        int ans = binarysearch(nums,target,0,pivotindex) ;
        return ans ;
     } 

     else{
        int ans = binarysearch(nums,target,pivotindex+1,n-1) ;
        return ans ;
     }
      return -1 ;
    }

};