void countApplesAndOranges(int houseStart, int houseEnd, int appleTree, int orangeTree, vector<int> appleDistances, vector<int> orangeDistances) {
    int applesLanded = 0;
    int orangesLanded = 0;
    
    for (int i = 0; i < appleDistances.size(); i++){
        int applePosition = appleDistances[i] + appleTree;
        if (applePosition >= houseStart && applePosition <= houseEnd){
            applesLanded++;
        }
    }
    
    for (int i = 0; i < orangeDistances.size(); i++){
        int orangePosition = orangeDistances[i] + orangeTree;
        if (orangePosition >= houseStart && orangePosition <= houseEnd){
            orangesLanded++;
        }
    }
    
    cout << applesLanded << endl;
    cout << orangesLanded;
}
