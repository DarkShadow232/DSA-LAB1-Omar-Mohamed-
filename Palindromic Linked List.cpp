are corresponding nodes in the two halves of the lists.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* nextNode;
        
        while(current != NULL){
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        
        return previous;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* reversedSecondHalf = reverseList(slow);
        
        ListNode* firstHalfPointer = head;
        ListNode* secondHalfPointer = reversedSecondHalf;
        
        while(secondHalfPointer != NULL){
            if(firstHalfPointer->val != secondHalfPointer->val){
                return false; 
            }
            firstHalfPointer = firstHalfPointer->next;
            secondHalfPointer = secondHalfPointer->next;
        }
        
        return true; 
    }
};

