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
    void reorderList(ListNode* head) {
        ListNode* slow = head, * fast = head;
        if(!head->next) return;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * secondHalf = nullptr, * temp, *curr;
        curr = slow->next;
        slow->next = nullptr;

        // cout<<slow->val<<endl;
        while(curr) {
            temp = curr->next;
            curr->next = secondHalf;
            secondHalf = curr;
            curr = temp;
        }
        ListNode * l = new ListNode(0);
        curr = l;
        // secondHalf = secondHalf;
        while(head || secondHalf) {
            
            if(head) {
                curr ->next = head;
                head = head->next;
                curr = curr->next;
            }
            if(secondHalf) {
                curr ->next = secondHalf;
                secondHalf = secondHalf->next;
                curr = curr->next;
            }
        }
        head = l->next;
        return ;
    }
};
