class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int diff = 0;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] > prices[buy]){
                if(prices[i] - prices[buy] > diff){
                    diff = prices[i] - prices[buy];
                }
            }
            else{
                buy = i;
            }
        }
        return diff;
    }
};
