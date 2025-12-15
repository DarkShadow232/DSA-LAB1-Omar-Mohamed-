vector<int> breakingRecords(vector<int> scores) {
    int lowestScore = scores[0];
    int highestScore = scores[0];
    int lowestRecordBreaks = 0;
    int highestRecordBreaks = 0;
    
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > highestScore) {
            highestRecordBreaks++;
            highestScore = scores[i];
        }
        else if (scores[i] < lowestScore) {
            lowestRecordBreaks++;
            lowestScore = scores[i];
        }
    }
    
    vector<int> result = {highestRecordBreaks, lowestRecordBreaks};
    return result;
}
