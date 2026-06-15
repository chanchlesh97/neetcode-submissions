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
                temp = copyMap[curr->next];
                currNew->next = temp;
            } else {
                Node * v = new Node(curr->next->val);
                copyMap[curr->next] = v;
                currNew ->next = v;
               
            }
            if(curr->random){
                if(copyMap.find(curr->random) != copyMap.end()) {
                    temp = copyMap[curr->random];
                    currNew->random = temp;
                } else {
                    Node * v = new Node(curr->random->val);
                    copyMap[curr->random] = v;
                    currNew ->random = v;
                
                }
            }

            curr = curr->next;
            currNew = currNew->next;
        }

        return newHead;
    }
};
