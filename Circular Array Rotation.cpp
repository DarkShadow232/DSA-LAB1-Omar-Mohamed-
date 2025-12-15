vector<int> circularArrayRotation(vector<int> array, int rotations, vector<int> queries) {
    for (int i = 0; i < rotations; i++) {
        int lastElement = array.back();
        array.pop_back();
        array.insert(array.begin(), lastElement);
    }
    
    vector<int> result;
    
    for (int i = 0; i < queries.size(); i++) {
        result.push_back(array[queries[i]]);
    }
    
    return result;
}
