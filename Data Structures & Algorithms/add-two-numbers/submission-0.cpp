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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sum = nullptr, *temp, *curr;
        int rem = 0;
        while(l1 && l2) {
            temp = new ListNode((l1->val+l2->val+rem)%10);
            rem = (l1->val+l2->val+rem)/10;
            if(!sum) {
                sum = temp;
                curr = temp;
            } else {
                curr ->next = temp;
            curr = curr->next;

            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            temp = new ListNode((l1->val+rem)%10);
            rem = (l1->val+rem)/10;

            curr ->next = temp;
            curr = curr->next;
            l1 = l1->next;
        }

        while(l2) {
            temp = new ListNode((l2->val+rem)%10);
            rem = (l2->val+rem)/10;

            curr ->next = temp;
            curr = curr->next;
            l2 = l2->next;
        }

        if(rem) {
            curr->next = new ListNode(rem);
        }
        return sum;
    }
};
