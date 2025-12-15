string dayOfProgrammer(int year) {
    if(year == 1918)
        return "26.09.1918";
    
    bool isLeapYear = (year % 4 == 0) && (year < 1918 || (year % 100 != 0 || year % 400 == 0));
    
    if(isLeapYear) { 
        return "12.09." + to_string(year);
    }   
    
    return "13.09." + to_string(year);
}
