class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq ;
        for(auto task:tasks){
            freq[task]++ ;
        }

     priority_queue<pair<int,char>,vector<pair<int,char>>> maxHeap ;

     for(auto each : freq){
        maxHeap.push({each.second,each.first}) ;
     }

     int ans = 0 ;
     while(!maxHeap.empty()){
        int cycle = n+1 ;
        vector<pair<int,char>>temp ;

      while(cycle>0 && !maxHeap.empty()){
        auto[freq,task] = maxHeap.top() ;
        maxHeap.pop() ;
        freq-- ;
        ans++ ;
        cycle-- ;
        temp.push_back({freq,task}) ;
      }

      for(auto leftTask:temp){
        if(leftTask.first>0){
            maxHeap.push(leftTask) ;
        }
      }

        if(!maxHeap.empty()){
            ans += cycle ;
        }    
     }
       return ans ;
    }
};