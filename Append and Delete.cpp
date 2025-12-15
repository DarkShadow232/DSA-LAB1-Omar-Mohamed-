string appendAndDelete(string source, string target, int operations) {
    int sourceLength = source.length();
    int targetLength = target.length();
    int smallerLength = sourceLength < targetLength ? sourceLength : targetLength;
    
    int commonPrefixLength = smallerLength;
    for(int i = 0; i < smallerLength; i++){
        if(source[i] != target[i]){
            commonPrefixLength = i;
            break;
        }
    }
    
    int operationsNeeded = (sourceLength + targetLength) - 2 * commonPrefixLength;
    
    if(operationsNeeded == operations) return "Yes";
    else if(operationsNeeded < operations && (2 * commonPrefixLength + operationsNeeded <= operations)) return "Yes";
    else if(operationsNeeded < operations && (operations - operationsNeeded) % 2 == 0) return "Yes";
    else return "No";    
}
