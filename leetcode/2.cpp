/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int value = l1->val + l2->val;
        int value_now = value % 10;
        int value_overflow = value / 10;
        ListNode *root = new ListNode(value_now);
        ListNode *last = root;
        while (l1->next || l2->next || value_overflow > 0) {
            if (l1->next)
                l1 = l1->next, value_overflow += l1->val;
            if (l2->next)
                l2 = l2->next, value_overflow += l2->val;
            value_now = value_overflow % 10;
            value_overflow /= 10;
            
            ListNode *pre_last = last;
            last = new ListNode(value_now);
            pre_last->next = last;
        }
        return root;
    }
};
