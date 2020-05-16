/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    pair<ListNode*,ListNode*> myReverse(ListNode* head,ListNode* tail)
    {
        ListNode* prev = tail->next;
        ListNode* cur = head;
        ListNode* next;
        while(prev!=tail)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy(0);
        ListNode* pre;
        dummy->next = head;
        pre = dummy;
        ListNode* p = head;
        int l = 0;
        while(p)
        {
            p = p->next;
            l++;
        }
        for (int i = 0; i < l/k; i++)
        {
            ListNode* tail = head;
            for (int j = 0; j < k-1; j++)
            {
                tail = tail->next;
            }
            pair<ListNode*,ListNode*> x = myReverse(head,tail);
            head = x.first;
            tail = x.second;
            pre->next = head;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};