vector<int> compareTriplets(vector<int> aliceScores, vector<int> bobScores) {
    int alicePoints = 0;
    int bobPoints = 0;
    
    for (int i = 0; i < aliceScores.size(); i++) {
        if (aliceScores[i] > bobScores[i]) {
            alicePoints++;
        }
        else if (bobScores[i] > aliceScores[i]) {
            bobPoints++;
        }
    }
    
    return vector<int> {alicePoints, bobPoints};
}
