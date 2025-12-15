int getTotalX(vector<int> firstArray, vector<int> secondArray) {
    int firstSize = firstArray.size();
    sort(firstArray.begin(), firstArray.end());
    
    int secondSize = secondArray.size();
    sort(secondArray.begin(), secondArray.end());
    
    int count = 0;
    
    for(int number = firstArray[firstSize - 1]; number <= secondArray[0]; number++){
        bool isValid = true;
        
        for(int j = 0; j < firstSize; j++){
            if(number % firstArray[j] != 0){
                isValid = false;
                break;
            }
        }
        
        if(isValid){
            for(int k = 0; k < secondSize; k++){
                if(secondArray[k] % number != 0){
                    isValid = false;
                    break;
                }
            }
        }
        
        if(isValid)
            count++;
    }
    
    return count;
}
