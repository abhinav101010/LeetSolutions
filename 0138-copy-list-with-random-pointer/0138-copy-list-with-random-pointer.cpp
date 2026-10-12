/**
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     Node* next;
 *     Node* random;
 *     Node(int _val) {
 *         val = _val;
 *         next = nullptr;
 *         random = nullptr;
 *     }
 * };
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create interleaved copies
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the lists
        curr = head;
        Node* copyHead = head->next;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        
        return copyHead;
    }
};