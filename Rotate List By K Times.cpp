
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int cnt = 0;
        ListNode* trav = head;
        ListNode* lastNode = head;
        
        while(trav != NULL){
            cnt++;
            lastNode = trav;
            trav = trav->next;
        }
        
        k %= cnt;
        
        if(k == 0){
            return head;
        }
        
        int skip = cnt - k - 1;
        
        trav = head;
        
        while(skip--){
            trav = trav->next;
        }
        
        ListNode *newHead = trav->next;
        trav->next = NULL;
        
        lastNode->next = head;
        
        return newHead;
        
    }
};

