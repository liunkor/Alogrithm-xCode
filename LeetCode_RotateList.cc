/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        
        if(head == NULL  || k <= 0)     //K为非负值
            return head;
        
        int len = 0;
        ListNode *p = head;
        while(p != NULL) {
            len++;
            p = p->next;
        }
        
        if(len == 1)                   //难点：对K的边界值的处理，k<=0、k > len （注意取余后的k值是否为0）
            return head;
        if(len == k)
            return head;
        if(len < k) {                 // （注意取余后的k值是否为0的判断）
            k = k % len;
            if(k == 0)
                return head;
        }
            
        ListNode *pre = head;
        for(int i = 0; i < len - k - 1; i++)
            pre = pre->next;
            
        p = pre->next;
        pre->next = NULL; 
        ListNode *newhead = p;
        while(p->next != NULL) 
            p = p->next;
          
        p->next = head;
        head = newhead;
        return newhead;
        
    }
};
