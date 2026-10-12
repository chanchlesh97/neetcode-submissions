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
    unordered_map<int, Node*> nodeMap;
    unordered_map<int,bool> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node ) return nullptr;
        if(nodeMap.find(node->val) != nodeMap.end()) 
        return nodeMap[node->val];
        cout<<node->val<<" ";
        Node * temp = new Node(node->val);
        nodeMap[node->val] = temp;
       


        for(Node * n: node->neighbors) {
            temp->neighbors.push_back(cloneGraph(n));
        }
        return temp;

    }
};
