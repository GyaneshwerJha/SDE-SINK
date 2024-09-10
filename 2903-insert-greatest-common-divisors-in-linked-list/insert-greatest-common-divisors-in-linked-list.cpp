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
    int findGcd(int a, int b){
        return b == 0 ? a : findGcd(b, a % b);    
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = new ListNode(head->val);
        dummy->next = ans;
        ListNode *temp = head->next;
        while(temp != nullptr){
            int gcd = findGcd(ans->val, temp->val);
            ListNode *gcdNode = new ListNode(gcd);
            ans->next = gcdNode;
            ans = ans->next;
            ans->next = temp;
            ans = ans->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};