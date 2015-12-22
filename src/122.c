int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int profit;
    int i;
    
    for (i = 1; i < pricesSize; i++)
    {
        profit = prices[i] - prices[i - 1];
        if (profit > 0)
            max += profit;
    }
    
    return max;
}