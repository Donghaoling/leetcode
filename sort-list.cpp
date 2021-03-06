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
     ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dump(0);
        ListNode* cur = &dump;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;

        return dump.next;
    }
    ListNode* sortList(ListNode* head) {
    	if (head == NULL || head->next == NULL) return head;
    	ListNode *slow = head;
    	ListNode *fast = head;
    	while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	ListNode *beg2 = slow->next;
    	slow->next = NULL;
    	return merge(sortList(head), sortList(beg2));
    }
};
