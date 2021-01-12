/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
        // p and q are both null
    if (p == NULL && q == NULL) 
        return true;
    // one of p and q is null
    if (q == NULL || p == NULL) 
        return false;
    if (p->val != q->val) 
        return false;
    return isSameTree(p->right, q->right) &&
            isSameTree(p->left, q->left);
}