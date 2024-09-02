/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *temp = head;
        ListNode *tail = head;
        while(tail != nullptr && tail->next != nullptr){
            tail = tail->next->next;
            temp = temp->next;
        }
        tail = temp;
        ListNode *prev = NULL;
        while(temp != NULL){
            tail = temp->next;
            temp->next = prev;
            prev = temp;
            temp = tail;
        }
        while(prev != NULL && head != NULL){
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};