// class Solution {
// public:
    // int maxProfit(vector<int>& prices) {
        // int buy = 0;
        // int diff = 0;
        // for(int i = 0;i<prices.size();i++){
            // if(prices[i] > prices[buy]){
                // if(prices[i] - prices[buy] > diff){
                    // diff = prices[i] - prices[buy];
                // }
            // }
            // else{
                // buy = i;
            // }
        // }
        // return diff;
    // }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (int price : prices) {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};
