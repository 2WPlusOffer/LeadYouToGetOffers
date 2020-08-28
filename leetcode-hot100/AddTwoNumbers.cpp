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
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        int digit, carry = 0;
        int v1, v2;
        while (l1 || l2) {
            
            v1 = l1 != nullptr? l1->val: 0;
            v2 = l2 != nullptr? l2->val: 0;
            digit = (v1 + v2 + carry) % 10;
            head->next = new ListNode(digit);
            head = head->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            carry = (v1 + v2 + carry) / 10;
        }
        if (carry) head->next = new ListNode(1);
        return res->next;
        
    }
};