/*
99. 恢复二叉搜索树
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int count = 0;
    TreeNode* pre = NULL;
    TreeNode* p1 = NULL;
    TreeNode* p2 = NULL;
    void swap()
    {
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
    void inOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        inOrder(root->left);
        if(pre)
        {
            if(pre->val>root->val)
            {
                if(!p1) p1 = pre;
                p2 = root;
            }
        }
        pre = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap();
    }
};