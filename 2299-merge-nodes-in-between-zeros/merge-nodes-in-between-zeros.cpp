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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head->next;

        int currSum = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;
        while(temp != nullptr){
            if(temp->val != 0){
                currSum += temp->val;
            }
            else{
                ans->next = new ListNode(currSum);
                ans = ans->next;
                currSum = 0;
            }
            temp = temp->next;
        }
        // ans->next = nullptr;
        return dummy->next;
    }
};