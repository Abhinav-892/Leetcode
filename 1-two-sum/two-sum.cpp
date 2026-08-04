class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> data ;
        vector<int> temp ;

    for(int i=0 ; i<nums.size() ; i++){
        int index = i ;
        int val = nums[i] ;
        data.push_back({val,index}) ;
    }
         
    sort(data.begin(),data.end()) ;

    int s = 0 ;
    int e = nums.size()-1 ;
    int sum ;

    while(s<e){
   
   sum = data[s].first + data[e].first ;

   if(sum==target){
    temp.push_back(data[s].second) ;
    temp.push_back(data[e].second) ;
    break ;
   }

   else if(sum>target){
    e-- ;
   }

   else{
    s++ ;
   }
    }
     return temp ;
    }
};