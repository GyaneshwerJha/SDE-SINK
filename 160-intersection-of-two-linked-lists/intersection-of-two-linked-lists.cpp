/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA != nullptr){
            len1++;
            tempA = tempA->next;
        }

        while(tempB != nullptr){
            len2++;
            tempB = tempB->next;
        }

        int diff = abs(len1 - len2);

        if(len1 > len2){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }
        else{
            while(diff){
                headB = headB->next;
                diff--;
            }
        }

        tempA = headA;
        tempB = headB;
        while(tempA != nullptr){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;
    }
};