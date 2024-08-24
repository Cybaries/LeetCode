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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        // if (cnt == 1 && n == 1) return NULL;
        cnt -= n;
        temp = new ListNode(-1, head);
        ListNode* ans = temp;
        while(temp != NULL){
            if (cnt == 0){
                temp->next = temp->next->next;
            }
            cnt--;
            temp = temp->next;
        }
        return ans->next;
    }
};