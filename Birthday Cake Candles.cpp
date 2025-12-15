int birthdayCakeCandles(vector<int> candles) {
    sort(candles.begin(), candles.end());
    
    int tallestCandleCount = 1;
    int arraySize = candles.size();
    int tallestHeight = candles[arraySize - 1];
    
    for (int i = 0; i < arraySize - 1; i++) {
        if (candles[i] == tallestHeight) {
            tallestCandleCount++;
        }
    }
    
    return tallestCandleCount;
}
