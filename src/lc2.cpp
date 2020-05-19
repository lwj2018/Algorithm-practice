/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* head = new ListNode(0);
        ListNode* lastNode = head;
        while(l1||l2)
        {
            int x;
            if(l1&&l2)
            {
                x = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1)
            {
                x = l1->val;
                l1 = l1->next;
            }
            else if(l2)
            {
                x = l2->val;
                l2 = l2->next;
            }
            x = x + c;
            if(x>=10)
            {
                x = x-10;
                c = 1;
            }
            else c = 0;
            ListNode * node = new ListNode(x);
            lastNode->next = node;
            lastNode = node;
        }
        if(c==1)
        {
            ListNode * node = new ListNode(1);
            lastNode->next = node;
            lastNode = node;
        }
        return head->next;
    }
};