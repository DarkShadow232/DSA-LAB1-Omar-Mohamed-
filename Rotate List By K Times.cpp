
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int rotations) {
        int listLength = 0;
        ListNode* current = head;
        ListNode* lastNode = head;
        
        while(current != NULL){
            listLength++;
            lastNode = current;
            current = current->next;
        }
        
        rotations %= listLength;
        
        if(rotations == 0){
            return head;
        }
        
        int stepsToNewTail = listLength - rotations - 1;
        
        current = head;
        
        while(stepsToNewTail--){
            current = current->next;
        }
        
        ListNode* newHead = current->next;
        current->next = NULL;
        
        lastNode->next = head;
        
        return newHead;
    }
};

