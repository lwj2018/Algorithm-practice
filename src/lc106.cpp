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
    TreeNode* reBuildTree(int postleft,int postright,int inleft,int inright,vector<int>& inorder, vector<int>& postorder) {
        int rootval = postorder[postright];
        TreeNode* root = new TreeNode(rootval);
        int rootind;
        for (int i = inleft; i <= inright; i++)
        {
            if(inorder[i]==rootval) rootind = i; 
        }
        int left = rootind - inleft;
        int right = inright - rootind;
        if(left>0) root->left = reBuildTree(postleft,postleft+left-1,inleft,rootind-1,inorder,postorder);
        if(right>0) root->right = reBuildTree(postleft+left,postright-1,rootind+1,inright,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()||inorder.empty()) return NULL;
        int l = inorder.size();
        return reBuildTree(0,l-1,0,l-1,inorder,postorder);
    }
};