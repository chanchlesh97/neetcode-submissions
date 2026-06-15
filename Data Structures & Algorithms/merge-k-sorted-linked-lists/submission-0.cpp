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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode*a, ListNode*b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>pq; 

        for(auto &l: lists) {
            pq.push(l);
        }
        ListNode * temp, *head = nullptr, *curr;
        while(!pq.empty()) {
            temp = pq.top();
            pq.pop();
            // cout
            if(!head) {
                head = temp;
                curr = temp;
            } else {
                curr->next = temp;
                curr = curr->next;
            }
            if(temp->next) {
                pq.push(temp->next);
            }

        }

        return head;
    }
};
