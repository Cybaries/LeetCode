/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Move through the list and check for the cycle.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Cycle detected, find the cycle start.
                fast = head;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // Cycle start node
            }
        }

        return nullptr;  // No cycle found
    }
};
