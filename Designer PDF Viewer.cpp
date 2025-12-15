int designerPdfViewer(vector<int> letterHeights, string word) {
    int wordLength = word.size();
    int tallestLetterHeight = 0; 
    
    for (int i = 0; i < wordLength; i++) {
        int letterIndex = word[i] - 'a';
        if (letterHeights[letterIndex] > tallestLetterHeight) {
            tallestLetterHeight = letterHeights[letterIndex];
        }
    }
    
    return tallestLetterHeight * wordLength;
}
