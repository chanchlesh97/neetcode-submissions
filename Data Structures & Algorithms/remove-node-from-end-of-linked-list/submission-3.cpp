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
    ListNode* removeNthFromEnd(ListNode* head, int  n) {
        int count = 0;
        ListNode * newHead = new ListNode(0, head);
        return removeNth(newHead,count, n)->next;
    }
ListNode* removeNth(ListNode* head,int&count, int  n) {
        if(!head) return nullptr;

        head->next = removeNth(head->next, count, n);
        // cout<<h->val<<" "<<count<<endl;
        if(n == count) {
            head ->next = head->next->next;
        }
        count++;
        
        return head;
    }

};
