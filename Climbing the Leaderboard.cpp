vector<int> climbingLeaderboard(vector<int> leaderboardScores, vector<int> playerScores) {
    vector<int> playerRanks;
    playerRanks.resize(playerScores.size());
    
    int currentRank = 0;
    int previousScore = -1;
    int playerIndex = playerScores.size() - 1;
    
    for (int i = 0; i < leaderboardScores.size() && playerIndex > -1; i++) {
        if (leaderboardScores[i] != previousScore) {
            previousScore = leaderboardScores[i];
            currentRank++;
            
            while ((playerScores[playerIndex] >= previousScore) && (playerIndex > -1)) {
                playerRanks[playerIndex--] = currentRank;
            }
        }
    }
    
    currentRank++;
    while (playerIndex > -1) {
        playerRanks[playerIndex--] = currentRank;
    }
    
    return playerRanks;
}
