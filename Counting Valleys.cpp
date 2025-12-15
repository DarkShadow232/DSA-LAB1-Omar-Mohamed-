int countingValleys(int steps, string path) {
    int currentLevel = 0;
    int valleyCount = 0;
    
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'U') {
            currentLevel++;
            if (currentLevel == 0) {
                valleyCount++;
            }
        }
        if (path[i] == 'D') {
            currentLevel--;
        }
    }
    
    return valleyCount;  
}
