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
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;

        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    void print(ListNode *head){
        ListNode *temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    ListNode *addTwo(ListNode *r1, ListNode *r2){
        ListNode *dummy = new ListNode(-1);
        ListNode *sumNode = dummy;
        int carry = 0;
        while(r1 != NULL || r2 != NULL || carry){
            int sum = 0;
            if(r1 != NULL){
                sum += r1->val;
                r1 = r1->next;
            }

            if(r2 != NULL){
                sum += r2->val;
                r2 = r2->next;
            }

            if(carry != 0){
                sum += carry;
            }

            int digit = sum % 10;
            carry = sum / 10;
            sumNode->next = new ListNode(digit);
            sumNode = sumNode->next;
        }
        return dummy->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = reverse(l1);
        ListNode *r2 = reverse(l2);
        print(r1);
        print(r2);
        ListNode *res = addTwo(r1,r2);

        return reverse(res);
    }
};