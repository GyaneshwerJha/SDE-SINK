// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;

        // Step 1: Create a copy of each node and insert it immediately after the original node
        while (temp != nullptr) {
            Node* curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = curr->next;
        }

        // Step 2: Assign random pointers for the copied nodes
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the copied list from the original list
        temp = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        while (temp != nullptr) {
            temp->next = temp->next->next;
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }
            temp = temp->next;
            copy = copy->next;
        }

        return copyHead;
    }
};
