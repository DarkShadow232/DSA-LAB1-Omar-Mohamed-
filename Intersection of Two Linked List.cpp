

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int list1count = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){
            list1count++;
            tempA = tempA->next;
        }
        
        int list2count = 0;
        ListNode* tempB = headB;
        while(tempB != NULL){
            list2count++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        if(list2count > list1count){
            int diff = list2count - list1count;
            while(diff--){
                tempB = tempB->next;
            }
        }else if(list2count < list1count){
            int diff = list1count - list2count;
            while(diff--){
                tempA = tempA->next;
            }
        }
        
        while(tempA != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* D1 = headA;
        ListNode* D2 = headB;
        
        while(D1 != D2){
            if(D1 == NULL){
                D1 = headB;
            }else{
                D1 = D1->next;
            }
            
            if(D2 == NULL){
                D2 = headA;
            }else{
                D2 = D2->next;
            }
        }
        
        return D1;
       
    }
};



