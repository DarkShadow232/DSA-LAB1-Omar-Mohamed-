int reverseNumber(int number) {
    int reversed = 0;
    
    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }
    
    return reversed;
}

int beautifulDays(int startDay, int endDay, int divisor) {
    int beautifulDayCount = 0;
    
    for (int day = startDay; day <= endDay; day++) {
        int reversedDay = reverseNumber(day);
        int difference = abs(day - reversedDay);
        
        if (difference % divisor == 0) {
            beautifulDayCount++;
        }
    }
    
    return beautifulDayCount;
}
