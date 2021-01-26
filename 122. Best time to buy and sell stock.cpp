class Solution {
public:
    int maxprofit(vector<int>& prices) {
        int bd=0;
        int sd=0;
        int profit=0;
        for(int i = 1;i<prices.size();i++){
             if(prices[i]>=prices[i-1]){
                  sd++;
             }
             else{
                 profit+=prices[sd]-prices[bd];
                 bd=i;
                 sd=I;
              }
        }

       profit+=prices[sd]-prices[bd];
        return profit;
    }
};