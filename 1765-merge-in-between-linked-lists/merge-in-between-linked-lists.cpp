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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        int len = 0;
        ListNode *first = list1;
        ListNode *last = list1;
        // find a pos
        cout<<"first"<<endl;
        while(len < a - 1 && first != NULL){
            first = first->next;
            cout<<first->val<<endl;

            len++;
        }
        cout<<endl;

        cout<<"last"<<endl;
        len = 0;
        // find b pos and b next pos
        while(len < b && last->next != NULL){
            last = last->next;
            cout<<last->val<<endl;
            len++;
        }
        ListNode *nextLast = nullptr;
        if(last->next != NULL){
            nextLast = last->next;
        }
        last->next = nullptr;

        // find end of list 2
        last = list2;
        while(last->next != nullptr){
            last = last->next;
        }

       
        // final step merge
        if(first != nullptr){
            first->next = list2;
        }
        last->next = nextLast;
        return list1;
    }
};