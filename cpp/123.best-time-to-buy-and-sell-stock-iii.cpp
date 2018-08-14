class Solution {
private:
    vector<int> leftProfit, rightProfit;
    
    void calLeftProfit(vector<int>& prices) {
        leftProfit.resize(prices.size(), 0);
        int minIndex = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[minIndex]) minIndex = i;
            leftProfit[i] = max(leftProfit[i-1], prices[i]-prices[minIndex]);
        }
    }
    
    void calRightProfit(vector<int>& prices) {
        rightProfit.resize(prices.size()+1, 0);
        int maxIndex = prices.size()-1;
        for (int i = prices.size()-2; i >= 0; i--) {
            if (prices[i] > prices[maxIndex]) maxIndex = i;
            rightProfit[i] = max(rightProfit[i+1], prices[maxIndex] - prices[i]);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        calLeftProfit(prices);
        calRightProfit(prices);
        int ans = 0;
        for (int i = 1; i <= prices.size(); i++) {
            ans = max(ans, leftProfit[i-1]+rightProfit[i]);
        }
        return ans;
    }
};
