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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *nextNode = nullptr;

        while(temp != nullptr){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
};