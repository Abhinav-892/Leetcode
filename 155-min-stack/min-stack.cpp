class MinStack {
public:

   vector<pair<int,int>>v ;
  
    MinStack() {
        
    }
    
    void push(int value) {
        
     if(v.empty()){
        v.push_back({value,value}) ;
        return ;
     }

     auto top = v.back() ;
     int minelement = min(value,top.second) ;

     v.push_back({value,minelement}) ;

    }
    
    void pop() {
        v.pop_back() ;
    }
    
    int top() {
        return v.back().first ;
    }
    
    int getMin() {
        return v.back().second ;
    }
};
