// Last updated: 11/05/2026, 01:33:01
/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // while(node->next != NULL){
            node->val = node->next->val;
            node->next = node->next->next;
        // }
    }
};