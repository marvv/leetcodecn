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
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* result = NULL;
        ListNode* tail = NULL;
        int plus1 = 0;
        while (p != NULL && q != NULL)
        {
            int tmp = p->val + q->val + plus1;
            if (tmp >= 10)
            {
                plus1 = 1;
                tmp = tmp - 10;
            } 
            else
            {
                plus1 = 0;
            }
            ListNode* node = new ListNode(tmp);
            if (tail == NULL)
            {
                result = node;
                tail = node;
            }
            else 
            {
                tail->next = node;
                tail = node;
            }
            p = p->next;
            q = q->next;
        }
        
        while (p != NULL)
        {
            int tmp = p->val + plus1;
            if (tmp >= 10)
            {
                plus1 = 1;
                tmp = tmp - 10;
            }
            else
            {
                plus1 = 0;
            }
            ListNode* node = new ListNode(tmp);
            if (result == NULL)
            {
                result = node;
                tail = node;
            }
            else 
            {
                tail->next = node;
                tail = node;
            }
            p = p->next;
        }
        
        while (q != NULL)
        {
            int tmp = q->val + plus1;
            if (tmp >= 10)
            {
                plus1 = 1;
                tmp = tmp - 10;
            }
            else
            {
                plus1 = 0;
            }
            ListNode* node = new ListNode(tmp);
            if (result == NULL)
            {
                result = node;
                tail = node;
            }
            else 
            {
                tail->next = node;
                tail = node;
            }
            q = q->next;
        }
        
        if (plus1)
        {
            ListNode* node = new ListNode(1);
            tail->next = node;
            tail = node;
        }
        return result;
     }
};