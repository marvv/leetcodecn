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
        ListNode* tmp = new ListNode(0);
        tmp ->next = head;
        ListNode* p = tmp;
        ListNode* q = tmp;
        
        for (int i = 0; i<n+1;i++)
        {
            if (q != NULL)
            {
                q = q->next;
            }
            else
            {
                return NULL;
            }         
        }
        
        while (q != NULL)
        {
            q = q->next;
            p = p->next;
        }
        
        p->next = p->next->next;
        return tmp->next;
        
    }
};