// Last updated: 11/05/2026, 01:33:35
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(node);
        mp[node] = new Node(node->val);
        while(q.size()){
            auto x = q.front();q.pop();
            for(auto i:x->neighbors){
                if(!mp[i]){
                    mp[i] = new Node(i->val);
                    q.push(i);
                    
                }
                mp[x]->neighbors.push_back(mp[i]);
            }
        }return mp[node];
    }
};