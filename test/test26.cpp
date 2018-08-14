#include <iostream>

//将一个二叉搜索树转换成一个排序的双向链表
 struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
 };
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;

        }
        TreeNode* head = NULL;
        ConvertList(pRootOfTree,head);
        //遍历左子树，找到左子树中的叶子节点，它就是排序链表的头结点
        TreeNode* cur = pRootOfTree;
        while(cur->left != NULL)
        {
            cur = cur->left;

        }

        return cur;

    }
    void ConvertList(TreeNode* root,TreeNode*& head)
    {
        if(root == NULL)
        {
            return;

        }
        ConvertList(root->left,head);
        root->left = head;
        if(head != NULL)
        {
            head->right = root;

        }
        head = root;
        ConvertList(root->right,head);

    }

};
