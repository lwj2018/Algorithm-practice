/*
98. 验证二叉搜索树
假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        if (!(root->right||root->left))
        {
            return true;
        }
        if (root->left)
        {
            int maxVal = max(root->left);
            if (maxVal>=root->val)
            {
                return false;
            }
        }
        if (root->right)
        {
            int minVal = min(root->right);
            if (minVal<=root->val)
            {
                return false;
            }
        }
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        return true;
        
    }
    int min(TreeNode* root)
    {
        int val;
        while (root)
        {
            val = root->val;
            root = root->left;
        }
        return val;
    }
    int max(TreeNode* root)
    {
        int val;
        while (root)
        {
            val = root->val;
            root = root->right;
        }
        return val;
    }
};