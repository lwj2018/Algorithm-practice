/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
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
    bool isInverse(TreeNode* left,TreeNode* right) {
        if(left&&!right) return false;
        if(!left&&!right) return false;
        if(!left&&!right) return true;
        if(left->val!=right->val) return false;
        return isInverse(left->right,right->left) && isInverse(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isInverse(root->left,root->right);
    }
};