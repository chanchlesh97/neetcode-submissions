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
      int count = 0;
      ListNode* newHead = new ListNode(0, head), *curr = newHead;

        while(curr) {
            curr = curr->next;
            count++;
        }

        curr = newHead;
        int currCount = 1;
        while(currCount != count-n){
            currCount++;
            curr = curr->next;
        }

        curr->next = curr->next->next;
        return newHead->next;
    }
};
