are corresponding nodes in the two halves of the lists.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        
        while(cur!=NULL){
            
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
            
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* revHead = reverseList(slow);
        
        ListNode* firstHalf = head;
        ListNode* secondHalf = revHead;
        
        while(secondHalf != NULL){
            if(firstHalf->val != secondHalf->val){
                return false; 
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true; 
    }
};

