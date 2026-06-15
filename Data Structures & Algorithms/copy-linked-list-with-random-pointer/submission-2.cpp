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

        while(curr) {
            if(curr->next)
            if(copyMap.find(curr->next) != copyMap.end()) {
                currNew->next  = copyMap[curr->next];    
            } else {
                currNew ->next = copyMap[curr->next] = new Node(curr->next->val);
               
            }
            if(curr->random){
                if(copyMap.find(curr->random) != copyMap.end()) {
                    currNew->random = copyMap[curr->random];
                } else {
                    currNew ->random = copyMap[curr->random] = new Node(curr->random->val);
                
                }
            }

            curr = curr->next;
            currNew = currNew->next;
        }

        return newHead;
    }
};
