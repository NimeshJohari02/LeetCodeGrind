class StockSpanner {
public:
    int globalIdx =0;
    stack<pair<int,int>>stk;
    StockSpanner() {
    }
//     int next(int price) {
//         globalIdx++;
//      if(stk.empty()){
//          stk.push({price,globalIdx});
//          return globalIdx ;
//      }   
//      else if(!stk.empty() and stk.top().first>=price){
//          int ans = globalIdx-stk.top().second;
//         stk.push({price,globalIdx});
//         return ans;
//       }  
//     else if(!stk.empty() and stk.top().first < price){
//          while(!stk.empty() and stk.top().first < price)   {
//              stk.pop();
//          }
//             if(stk.empty()){
//                 return globalIdx;
//             }
//             else{
                
//                 int ans = globalIdx-stk.top().second;
//             stk.push({price,globalIdx});
//               return ans; 
//             }
//         }
//         return 0;
//     }
// };
    int next(int price) {
        int res = 1;
        while (!stk.empty() && stk.top().first <= price) {
            res += stk.top().second;
            stk.pop();
        }
        stk.push({price, res});
        return res;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */