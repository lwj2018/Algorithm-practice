/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
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
    int maxdepth = 0;
    void traversal(TreeNode* root,int depth) {
        if (depth>maxdepth)
        {
            maxdepth = depth;
        }
        if(root->left) traversal(root->left,depth+1);
        if(root->right) traversal(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        traversal(root,1);
        return maxdepth;
    }
};