/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/
#include<iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) return res;
        int depth = 0;
        q.push(root);
        while(!q.empty())
        {
            vector<int> layer;
            int size = q.size();
            while (size>0)
            {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
            res.push_back(layer);
        }
        return res;
    }
};