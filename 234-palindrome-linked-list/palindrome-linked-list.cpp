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
        ListNode *findMid(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode *mid = findMid(head);
        ListNode *rev = reverse(mid);

        ListNode *c1 = head;
        ListNode *c2 = rev;

        while (c2 != nullptr) { // Only need to traverse till end of the second half
            if (c1->val != c2->val) {
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        return true;
    }
};