// class Solution {
// public:
    // int maxProfit(vector<int>& prices) {
        // int buy = 0;
        // int sell = 0;
        // int diff = 0;
        // int sum = 0;
        // for(int i = 1;i<prices.size();i++){
            // if(prices[i] > prices[sell]){
                // if( prices[i] - prices[buy] > diff){
                    // sell = i;
                    // diff = prices[i] - prices[buy];
                // }
            // }
            // else{
                // buy = i;
                // sell = i;
                // sum += diff;
                // diff = 0;
            // }
        // }
        // return sum + diff;
    // }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};
