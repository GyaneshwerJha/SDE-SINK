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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode *curr = head->next;

        int cnt = 1;
        int i = -1, previous = -1;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        while(curr->next != nullptr){
            if(prev->val > curr->val && curr->val < curr->next->val){
                if(i == -1){
                    i = cnt;
                    previous = cnt;
                }
                else{
                    minDist = min(minDist, cnt - previous);
                    previous = cnt;
                    maxDist = max(maxDist, cnt - i);
                }
            }
            else if(prev->val < curr->val && curr->val > curr->next->val){
                if(i == -1){
                    i = cnt;
                    previous = cnt;
                }
                else{
                    minDist = min(minDist, cnt - previous);
                    previous = cnt;
                    maxDist = max(maxDist, cnt - i);
                }
            }
            
            prev = prev->next;
            curr = curr->next;
            cnt++;
        }

        if(i == -1 || minDist == INT_MAX || maxDist == INT_MIN){
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};