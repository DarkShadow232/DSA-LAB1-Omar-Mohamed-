
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        bool cycleFound = false;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                cycleFound = true;
                break;
            }
        }
        
        if(!cycleFound){
            return NULL;
        }
        
        ListNode* pointerFromStart = head;
        ListNode* pointerFromMeeting = slow;
        
        while(pointerFromStart != pointerFromMeeting){
            pointerFromStart = pointerFromStart->next;
            pointerFromMeeting = pointerFromMeeting->next;
        }
        
        return pointerFromStart;
    }
};


 
