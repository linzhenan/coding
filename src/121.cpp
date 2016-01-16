class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        
        vector<int> minPricePos = vector<int>(prices.size(), 0);
        vector<int> maxPricePos = vector<int>(prices.size(), 0);
        
        int minVal = prices[0];
        minPricePos[0] = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] < minVal) {
                minVal = prices[i];
                minPricePos[i] = i;
            }
            else {
                minPricePos[i] = minPricePos[i - 1];
            }
            
        int maxVal = prices[prices.size() - 1];
        maxPricePos[prices.size() - 1] = prices.size() - 1;
        for (int i = prices.size() - 2; i >= 0; i--)
            if (prices[i] > maxVal) {
                maxVal = prices[i];
                maxPricePos[i] = i;
            }
            else {
                maxPricePos[i] = maxPricePos[i + 1];
            }
        
        maxVal = 0;
        for (int i = 0; i < prices.size(); i++) {
            int diff = prices[maxPricePos[i]] - prices[minPricePos[i]];
            if (diff > maxVal)
                maxVal = diff;
        }
        
        return maxVal;
    }
};