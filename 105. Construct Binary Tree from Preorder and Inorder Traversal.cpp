/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/
class Solution {
public:
        TreeNode* build(int left, int right, vector<int>& preorder, int& preIndex)
        {

            if(left > right || preIndex >= preorder.size())
                return nullptr;

            int rootVal = preorder[preIndex];
            int inorderIndex = inorderMp[rootVal];

            TreeNode* root = new TreeNode(rootVal);
            preIndex++;

            root->left = build(left, inorderIndex-1, preorder, preIndex);
            root->right = build(inorderIndex+1, right, preorder, preIndex);

            return root; 

        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(preorder.empty() || inorder.empty())
                return nullptr;

            for(int i = 0 ; i < inorder.size(); i++)
                inorderMp[inorder[i]] = i ;

            int preIndex = 0;
            return build(0, inorder.size()-1, preorder, preIndex);
        }

private: 
        unordered_map<int,int> inorderMp;
};