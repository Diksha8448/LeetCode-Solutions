/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l1=maxDepth(root->left);
        int l2=maxDepth(root->right);
        return 1+max(l1,l2);
}