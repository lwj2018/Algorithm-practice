/*
给定一个二叉树，返回它的中序遍历。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;

        while (root)
        {
            s.push(root);
            root = root->left;
        }
        while (!s.empty())
        {
            TreeNode* x = s.top();
            s.pop();
            v.push_back(x->val);
            x = x->right;
            while(x)
            {
                s.push(x);
                x = x->left;
            }
        }
        return v;
        
    }
};
