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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* p = tmp;
        while (p->next && p->next->next)
        {
            ListNode* q = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        delete tmp;
        return tmp->next;
    }
};