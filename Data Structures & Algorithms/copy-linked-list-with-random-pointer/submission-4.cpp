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
        if(!head) return head;
        Node * newHead = new Node(head->val), *curr = head, *temp, *currNew;
        unordered_map<Node*, Node*> copyMap;

        copyMap[head] = currNew = newHead;
        copyMap[nullptr] = nullptr;

        while(curr) {
            // if(curr->next)
            if(copyMap.find(curr->next) == copyMap.end()) {
                copyMap[curr->next] = new Node(curr->next->val);    
            } 
            currNew ->next = copyMap[curr->next];
               
            // if(curr->random){
            if(copyMap.find(curr->random) == copyMap.end()) {
                copyMap[curr->random] = new Node(curr->random->val);;
            } 
            currNew ->random = copyMap[curr->random];
                
            // }

            curr = curr->next;
            currNew = currNew->next;
        }

        return newHead;
    }
};
