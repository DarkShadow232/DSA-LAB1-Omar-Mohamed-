string catAndMouse(int catAPosition, int catBPosition, int mousePosition) {
    int distanceCatA = abs(catAPosition - mousePosition);
    int distanceCatB = abs(catBPosition - mousePosition);
    
    if (distanceCatA < distanceCatB) {
        return "Cat A";
    }
    else if (distanceCatB < distanceCatA) {
        return "Cat B";
    }
    else {
        return "Mouse C";
    }
}
