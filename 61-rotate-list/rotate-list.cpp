/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = head;
        int len = 0;

        while(temp != nullptr){
            len++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;

        k = k % len;
        int required = len - k;
        temp = head;
        for(int i = 0; i < required - 1; i++){
            temp = temp->next;
        }
        ListNode * newHead = head;
        if(temp->next != nullptr){
            newHead = temp->next;
            cout<<newHead->val;
        }
        temp->next = nullptr;

        return newHead;

    }
};