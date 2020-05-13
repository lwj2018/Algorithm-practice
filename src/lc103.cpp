/*
103. 二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
                if(depth%2==0)
                    layer.push_back(node->val);
                else
                    layer.insert(layer.begin(),node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
            depth++;
            res.push_back(layer);
        }
        return res;
    }
};