/**
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node* child;
 * };
 */
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        dfs(head);
        return head;
    }
    
private:
    Node* dfs(Node* node) {
        Node* curr = node;
        Node* last = node;
        while (curr) {
            Node* next = curr->next;
            if (curr->child) {
                Node* childLast = dfs(curr->child);
                curr->next = curr->child;
                curr->child->prev = curr;
                childLast->next = next;
                if (next) next->prev = childLast;
                curr->child = nullptr;
                last = childLast;
            } else {
                last = curr;
            }
            curr = next;
        }
        return last;
    }
};