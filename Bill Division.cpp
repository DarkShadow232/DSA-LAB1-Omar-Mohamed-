void bonAppetit(vector<int> billItems, int itemNotEaten, int amountPaid) {
    int totalBill = 0;
    
    for(int i = 0; i < billItems.size(); i++){
        totalBill = totalBill + billItems[i];
    }
    
    totalBill = totalBill - billItems[itemNotEaten];
    int fairShare = totalBill / 2;
    
    if(fairShare == amountPaid) {
        cout << "Bon Appetit";
    } else {
        int overcharged = amountPaid - fairShare;
        cout << overcharged;
    }
}
