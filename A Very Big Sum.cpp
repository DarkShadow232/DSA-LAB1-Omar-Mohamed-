long aVeryBigSum(vector<long> numbers) {
    long total = 0;
    for (int i = 0; i < numbers.size(); i++) {
        total = total + numbers[i];
    }
    return total;
}
