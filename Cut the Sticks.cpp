vector<int> cutTheSticks(vector<int> stickLengths) {
    vector<int> result;
    int remainingSticks = stickLengths.size();
    
    while(remainingSticks){
        int shortestLength = *min_element(stickLengths.begin(), stickLengths.end());
        result.push_back(remainingSticks);
        stickLengths.erase(remove(stickLengths.begin(), stickLengths.end(), shortestLength), stickLengths.end());
        remainingSticks = stickLengths.size();
    }
    
    return result;
}
