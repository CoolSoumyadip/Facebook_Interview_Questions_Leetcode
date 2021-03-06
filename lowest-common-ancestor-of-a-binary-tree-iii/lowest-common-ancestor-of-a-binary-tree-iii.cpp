/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> set;
        
        while(p != NULL) {
            set.insert(p);
            p = p->parent;
        }
        
        while(q != NULL) {
            if(set.find(q) != set.end()) {
                return q;
            }
            q = q -> parent;
        }
        
        return NULL;
    }
};