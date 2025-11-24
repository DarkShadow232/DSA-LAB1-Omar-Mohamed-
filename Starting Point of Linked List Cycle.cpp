
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        bool isCycleFound = false;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                isCycleFound = true;
                break;
            }
        }
        
        if(!isCycleFound){
            return NULL;
        }
        
        ListNode* start = head;
        ListNode* end = slow;
        
        while(start != end){
            start = start->next;
            end = end->next;
        }
        
        return start;
        
    }
};


 
