

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        ListNode* currentA = headA;
        while(currentA != NULL){
            lengthA++;
            currentA = currentA->next;
        }
        
        int lengthB = 0;
        ListNode* currentB = headB;
        while(currentB != NULL){
            lengthB++;
            currentB = currentB->next;
        }
        
        currentA = headA;
        currentB = headB;
        
        if(lengthB > lengthA){
            int difference = lengthB - lengthA;
            while(difference--){
                currentB = currentB->next;
            }
        } else if(lengthA > lengthB){
            int difference = lengthA - lengthB;
            while(difference--){
                currentA = currentA->next;
            }
        }
        
        while(currentA != NULL){
            if(currentA == currentB){
                return currentA;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        
        return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
        
        while(pointerA != pointerB){
            if(pointerA == NULL){
                pointerA = headB;
            } else {
                pointerA = pointerA->next;
            }
            
            if(pointerB == NULL){
                pointerB = headA;
            } else {
                pointerB = pointerB->next;
            }
        }
        
        return pointerA;
    }
};



