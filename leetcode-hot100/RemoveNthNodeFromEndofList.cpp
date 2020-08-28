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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针
        if (head->next == nullptr) return nullptr;
        
        ListNode *fast = head, *slow = head;
        if (n == 1) {
            while (fast->next->next) {
                fast = fast->next;
            }
            fast->next = NULL;
            return head;
        }
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == head){
            return head->next;
        } else if(slow->next == nullptr) {
            slow = nullptr;
            return head;
        } else {
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        return head;
    }
};