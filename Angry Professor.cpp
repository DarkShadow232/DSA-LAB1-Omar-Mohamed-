string angryProfessor(int minimumStudents, vector<int> arrivalTimes) {
    int studentsOnTime = 0;
    
    for (int i = 0; i < arrivalTimes.size(); i++) {
        if (arrivalTimes[i] <= 0) {
            studentsOnTime++;
        }
    }
    
    if (studentsOnTime < minimumStudents) {
        return "YES";
    } else {
        return "NO";
    }
}
