/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*, Node*>mp;
        while(temp!=NULL){
            Node* n=new Node(temp->val);
            mp[temp]=n;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node* copy=mp[temp];
            copy->next=mp[temp->next];
            copy->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};