/*
572. 另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
*/
#include<iostream>
#include<vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!t)
        {
            return false;
        }
        if (s->val!=t->val)
        {
            return false;
        }
        if (s->left)
        {
            if (!isEqual(s->left,t->left))
            {
                return false;
            }
            
        }
        else if (t->left) return false;            
        if (s->right)
        {
            if (!isEqual(s->right,t->right))
            {
                return false;
            }
        }
        else if (t->right) return false;
        return true;
        
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isEqual(s,t)) return true;
        if (s->left)
        {
            if (isSubtree(s->left,t))
            {
                return true;
            }
        }
        if (s->right)
        {
            if (isSubtree(s->right,t))
            {
                return true;
            }
        }
        return false;
    }
};

