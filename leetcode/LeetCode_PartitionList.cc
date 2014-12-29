/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 

*/

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
    ListNode *partition(ListNode *head, int x) {
          if(head == NULL) 
			return NULL;

		ListNode *before = NULL;
		ListNode *after = NULL, *after_head = NULL;
		bool b_flag = true, a_flag = true;
		ListNode *p = head;

		while(p != NULL) {
			if(p->val < x) {
				if(b_flag) {
					head = p;
					before = head;
					b_flag = false;
				} else {
					before->next = p;
					before = before->next;
				}
				p = p->next;
				before->next = NULL;
			} else {
				if(a_flag) {
					after_head = p;
					after = after_head;
					a_flag = false;
				} else {
					after->next = p;
					after = after->next;
				}
				p = p->next;
				after->next = NULL;
			}
		} 
		
		if(before != NULL) {
			before->next = after_head;
			return head;
		} else {
			return after_head;
		}
    }
};
