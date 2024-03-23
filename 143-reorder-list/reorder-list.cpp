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
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
    
    ListNode *findRev(ListNode *head){
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nexti = nullptr;

        while(curr){
            nexti = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexti;
        }
        return prev;
    }

    void print(ListNode *head){
        ListNode *temp = head;
        while(temp != nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;


        ListNode *mid = findMid(head);
        ListNode *rev = findRev(mid);
        // cout<<mid->val<<endl;
    ListNode *dummy = new ListNode(-1);
    ListNode *merged = dummy;
    while (head && rev) {
        merged->next = head;
        merged = merged->next;
        head = head->next;
        
        merged->next = rev;
        merged = merged->next;
        rev = rev->next;
    }
    if (head) {
        merged->next = head;
    }
    if (rev) {
        merged->next = rev;
    }

    head = dummy->next;
    }
};