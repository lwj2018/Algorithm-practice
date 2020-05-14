/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。
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
    TreeNode* reBuildTree(int preleft,int preright,int inleft,int inright,vector<int>& preorder, vector<int>& inorder) {
        int rootval = preorder[preleft];
        TreeNode* root = new TreeNode(rootval);
        int rootind;
        for (int i = inleft; i <= inright; i++)
        {
            if(inorder[i]==rootval) rootind = i; 
        }
        int left = rootind - inleft;
        int right = inright - rootind;
        if(left>0) root->left = reBuildTree(preleft+1,preleft+left,inleft,rootind-1,preorder,inorder);
        if(right>0) root->right = reBuildTree(preleft+left+1,preright,rootind+1,inright,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()) return NULL;
        int l = inorder.size();
        return reBuildTree(0,l-1,0,l-1,preorder,inorder);
    }
};